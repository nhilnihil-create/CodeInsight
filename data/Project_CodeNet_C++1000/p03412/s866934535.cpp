#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++) 
#define ltype ll
#define rep(i,j,k) for(ltype (i)=(j);(i)<=(k);(i)++)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
const int inf=0x3f3f3f3f,
mod=1000000007;
const double pi=3.1415926535897932,
eps=1e-6;
int n,a[200005],b[200005],c[200005],fin;
int solve(int k){
    ll md=1<<(k+1);
    rep(i,1,n) c[i]=b[i]%md;
    sort(c+1,c+n+1);
    int ans=0;
    rep(i,1,n){
        int num=a[i]%md;
        int cur=(lower_bound(c+1,c+n+1,(1<<(k+1))-num)-1-lower_bound(c+1,c+n+1,(1<<k)-num))
        +(lower_bound(c+1,c+n+1,(1<<(k+2))-num)-1-lower_bound(c+1,c+n+1,(1ll<<(k+1))+(1<<k)-num));
        ans+=cur;
    }
    return ans&1;
}
int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",a+i);
    rep(i,1,n) scanf("%d",b+i);
    rep(i,0,28) fin+=solve(i)*(1<<i);
    printf("%d",fin);
    return 0;
}