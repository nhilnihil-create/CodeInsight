#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i,l,r) for(ll i = (l); i <= (ll)(r); i++)
#define rep3(i,l,r) for(ll i = (l); i >= (ll)(r); i--)
#define dup(x,y) (((x)+(y)-1)/(y)) // x/yの除算の切り上げ
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = 1001001001;
const ll INF = 1LL << 60;
const ll mod = 1000000007; //1000000007
const ld pi = acos(-1);
 
//xor演算
//a^b=b^a
//a^(b^c)=(a^b)^c
//a^a=0
//a+b=a^b + 2(a&b)
//(4a)^(4a+1)^(4a+2)^(4a+3)=0
 
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll n=s.size();
    ll dp[101010][5]={};
    dp[0][0]=1;
    rep2(i,0,n-1){
        rep2(j,0,3){
            if(s[i]=='?'){
                dp[i+1][j] = (dp[i][j]*3)%mod;
            }
            if(s[i]!='?'){
                dp[i+1][j] = dp[i][j]%mod;
            }
        }
            if(s[i]=='A'){
                dp[i+1][1] += dp[i][0]%mod;
            }
            if(s[i]=='B'){
                dp[i+1][2] += dp[i][1]%mod;
            }
            if(s[i]=='C'){
                dp[i+1][3] += dp[i][2]%mod;
            }
            if(s[i]=='?'){
                dp[i+1][1] += dp[i][0]%mod;
                dp[i+1][2] += dp[i][1]%mod;
                dp[i+1][3] += dp[i][2]%mod;
            }
        }
    cout << dp[n][3]%mod << '\n';
}
