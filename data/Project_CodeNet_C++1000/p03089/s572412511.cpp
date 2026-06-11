#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
int n,a[105];
vector<int> ans;
int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",a+i);
    rep(i,1,n){
        bool flg=0;
        per(j,n-i+1,1)
        if(a[j] == j){
            ans.pb(j);
            rep(k,j,n-i) a[k] = a[k+1];
            flg=1;
            break;
        }
        if(!flg) {
            puts("-1");
            return 0;
        }
    }
    per(i,(int)ans.size()-1,0) printf("%d\n",ans[i]);
    return 0;
}