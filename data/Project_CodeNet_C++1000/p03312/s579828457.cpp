#include <bits/stdc++.h>
#define F(i,n) for (int i=1; i<=(int)n; i++)
#define FF(i,n) for (int i=0; i<(int)n; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pi pair < int , int >
#define re(x) (int)x.size()
#define y1 u228
using namespace std;
typedef long long ll;
const int N = 2e5+228;
const int big = 2e9;
const int md = 1e9 + 7;
int n,i,k;
ll a[N],pr[N],ans;
vector < ll > v;
ll go(int i,int j,int k){
    return abs(pr[k]-pr[j]-(pr[j]-pr[i-1]));
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin>>n; ans=9e18;
    F(i,n) cin>>a[i];
    F(i,n) pr[i]=pr[i-1]+a[i];
    i=k=1;
    F(j,n){
        while (i<j && go(1,i,j)>go(1,i+1,j)) i++;
        while (k<n && go(j+1,k,n)>go(j+1,k+1,n)) k++;
        v.resize(0);
        v.pb(pr[i]); v.pb(pr[j]-pr[i]); v.pb(pr[k]-pr[j]); v.pb(pr[n]-pr[k]);
        sort(all(v));
        ans=min(ans,v[re(v)-1]-v[0]);
    }
    cout<<ans<<endl;
    return 0;
}





