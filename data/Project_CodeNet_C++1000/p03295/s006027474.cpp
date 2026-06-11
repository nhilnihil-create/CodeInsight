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
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_edges2(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B);}
#define endl "\n"

const ll MOD = 1000000007;

const int N = 1e5 + 5;
vector<int> T(N);
void update(int x,int val) {
    for(; x <= N; x += x&-x) T[x] += val;
}
int sum(int x) {
    int res = 0;
    for(; x > 0; x -= x&-x) res += T[x];
    return res;
}
int query(int l, int r) {
    return sum(r)-sum(l-1);
}
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > v(m);
    for(auto &i : v) cin >> i.ss >> i.ff;
    sort(all(v));

    for(auto i : v){
        auto l = i.ss;
        auto r = i.ff;
        if(query(l, r) == 0) update(r - 1, 1);
    }

    cout << query(1, n);
}

ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}