#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#include <cctype>
#include <locale>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<long long,long long> Pll;
#define fout(num) cout << fixed << setprecision(20) << (num) << endl
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
//vector<vector<ll>> dp(n,vector<ll>(n))
//exist x map o setconst ll MOD = 1e9+7;return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;
//2-dim:vector<vector<Type>> vv(n, vector<Type>(m, d));
//3-dim:vector<vector<vector<Type>>> vvv(n, vector<vector<Type>>(m, vector<Type>(l, d)));


signed main(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    //dp[i][j]=i:bit j:bool
    ll dp[50][2];
    rep(i,50)rep(j,2)dp[i][j]=-1;
    dp[49][0]=0; //kと同じ
    for(int bit=48;bit>=0;bit--){
        ll pl=(1ull<<bit);
        ll cnt=0;
        rep(i,n) if(a[i]&pl) cnt++;
        if(pl&k){
            if(dp[bit+1][0]>=0) dp[bit][0]=dp[bit+1][0]+(n-cnt)*pl;
            if(dp[bit+1][0]>=0) dp[bit][1]=dp[bit+1][0]+pl*cnt;
            if(dp[bit+1][1]>=0) chmax(dp[bit][1],dp[bit+1][1]+pl*max(n-cnt,cnt));
        }else{
            if(dp[bit+1][0]>=0) dp[bit][0]=dp[bit+1][0]+cnt*pl;
            if(dp[bit+1][1]>=0){
                chmax(dp[bit][1],dp[bit+1][1]+pl*max(n-cnt,cnt));
            }
        }
    }
    cout << max(dp[0][0],dp[0][1]) << endl;
}


