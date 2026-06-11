#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N>>S;
    string red, blue;
    ll r, b, min_roop, ans = 0;
    rep(s, (1LL<<N)){
        red = blue = "";
        rep(j,N) ((s>>j)&1 ? red.push_back(S[j]) : blue.push_back(S[j]));
        //reverse(ALL(red)), reverse(ALL(blue));
        r = red.size(), b = blue.size();
        //min_roop = min(r, b);
        mat dp(r+1, vec(b+1,0));
        dp[0][0] = 1;
        Rreps(revi, N*2, N){
            ll roop = N*2 + 1 - revi;
            rep(i, roop){
                ll j = roop - 1  - i;
                if(i > r || j > b) continue;
                if(i != 0) if(S[revi] == red[i - 1]) dp[i][j] += dp[i-1][j];
                if(j != 0) if(S[revi] == blue[j - 1]) dp[i][j] += dp[i][j-1];
                if(revi == N) ans += dp[i][j];
            }
        }
        /*if(s == 2){
            rep(i,r+1){
                rep(j,b+1) cout<<dp[i][j]<<' ';
                cout<<endl;
            }
        }*/
        //cout<<bitset<4>(s)<<' '<<ans<<endl;
    }
    cout<<ans<<endl;
}