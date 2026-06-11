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
#define chk(x) if(x>=mod) x-=mod
int n,dp[200005],w[200005],a[200005];
int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",a+i);
    dp[0] = 1;
    rep(i,1,n){
        if(i>1 && a[i] == a[i-1]) {
            dp[i] = dp[i-1];
            continue;
        }
        dp[i] = dp[i-1] + w[a[i]]; chk(dp[i]);
        w[a[i]] += dp[i-1]; chk(w[a[i]]);
    }
    printf("%d\n",dp[n]);
    return 0;
}