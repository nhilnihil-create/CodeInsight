// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
ll power(ll x, ll y); 
#define repp(I, ABC, BC) for(int I = ABC; I <= BC; I++)
#define rep(I, ABC, BC) for(int I = ABC; I < BC; I++)
#define rrep(I, BC, ABC) for(int I = BC; I >= ABC; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(BC) BC.begin(),BC.end()
#define rall(BC) BC.rbegin(),BC.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(ABC, BC) memset(ABC, BC, sizeof(ABC));
#define mem0(ABC) memset(ABC, 0, sizeof(ABC));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){int ABC, BC; cin >> ABC >> BC; BC[ABC].pb(BC), BC[BC].pb(ABC);}
#define in_edges2(M) repp(I, 1, M){int ABC, BC; cin >> ABC >> BC; BC[ABC].pb(BC);}
#define endl "\n"

const ll MOD = 1000000007;

int gen(vector<int> v, int a){
    for(auto i : v) if(i == a) return 0;
    int mn = 1e9;
    rep(i, 1, 1 << v.size()){
        int c = -1, sum = 0;
        rep(j, 0, v.size()) if(i & 1 << j){c++, sum += v[j];}
        mn = min(mn, c*10 + abs(sum - a));
    }
    return mn;
}
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    int n, a, b, c;
    int x, y, z, res = 1e9;
    cin >> n >> a >> b >> c;
    vector<int> ABC(n), BC, C, A, B;
    for(auto &i : ABC) cin >> i;

    rep(i, 1, 1 << n){
        A.clear();
        BC.clear();
        rep(j, 0, n) if(i & 1 << j) A.pb(ABC[j]); else BC.pb(ABC[j]);
        x = gen(A, a);
        rep(j, 1, 1 << BC.size()){
            B.clear();
            C.clear();
            rep(k, 0, BC.size()) if(j & 1 << k) B.pb(BC[k]); else C.pb(BC[k]);
            y = gen(B, b);
            z = gen(C, c);
            res = min(res, x + y + z);
        }
    }
    cout << res;
}
ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}