/*input
20
>>>><>>><>><>>><<>>
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll = long long;
using ld = long double;
using pii = pair<ld,ld>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll INF64=4e18;
const int INF=1e6+1;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
ll sub(ll a,ll b){
    ll x=a-b;
    while(x<0) x+=MOD;
    while(x>MOD) x-=MOD;
    return x;
}
ll mult(ll a,ll b){
    return a*b%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=(res*a);
        if(res>1e10) return 1e11;
        a=(a*a);
        b>>=1;
    }
    return res;
}
const ll maxn=3005;
const ll maxlg=__lg(maxn)+2;
ll dp[maxn][maxn];
int main(){
    int n;
    string cmp;
    cin>>n>>cmp;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        vector<ll> pref(i);
        REP1(j,i-1){
            pref[j]=(pref[j-1]+dp[i-1][j])%MOD;
        }
        REP1(j,i){
            int l=0,r=0;
            if(cmp[i-2]=='<') l=j,r=i-1;
            else l=1,r=j-1;
            if(l<=r) dp[i][j]=(dp[i][j]+pref[r]-pref[l-1]+MOD)%MOD;
        }
    }
    ll sum=0;
    REP1(i,n) sum=(sum+dp[n][i])%MOD;
    cout<<sum;
}