// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(A, B) memset(A, B, sizeof(A));
#define mem0(A) memset(A, 0, sizeof(A));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define in_edges(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_edges2(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B);}
#define endl "\n"
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitsf(n) __builtin_popcount(n)
ll power(ll x, ll y); 

const ll MOD = 1000000007;
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    string s;
    cin >> s;
    vector<int> v;
    rep(i, 0, s.size()) if(s[i] == 'B') v.pb(i);
    int n = v.size(), r = s.size() - 1;
    ll res = 0;

    rrep(i, n-1, 0) res += (ll)(r - (n - 1 - i) - v[i]);

    cout << res;
}
 
ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}
