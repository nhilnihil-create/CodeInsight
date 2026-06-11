#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end(); ++it)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = ~(1<<31);
#define fs first
#define sc second
#define pb push_back

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
    return (a % b + b) % b;
}

ll n;
ll memo[1020][20'020];

ll W[1020];
ll S[1020];
ll V[1020];

vi I;
ll comp(ll a, ll b) {
    return (W[a]+S[a]) > (W[b]+S[b]);
}

ll dp(ll at, ll can_put) {
    if(at >= n) return 0;
    if(can_put == 0) return 0;
    if(memo[at][can_put] != -1) return memo[at][can_put];

    ll mx = dp(at+1,can_put);

    if(W[I[at]] <= can_put) {
        mx = max(mx, dp(at+1,  min(can_put - W[I[at]], S[I[at]])) + V[I[at]]);
    }

    return memo[at][can_put] = mx;
}

int main() {
    cin.sync_with_stdio(false);
    memset(memo,-1,sizeof(memo));
    cin >> n;
    rep(i,0,n) {
        cin >> W[i] >> S[i] >> V[i];
    }

    rep(i,0,n) I.pb(i);
    sort(I.begin(), I.end(), comp);
    cout << dp(0,20'000) << endl;
    return 0;
}


