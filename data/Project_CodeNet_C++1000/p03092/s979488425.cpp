#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,q;
const ll big = 1000000007;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

const ll MAXN = 5001;

ll P[MAXN];
ll P2[MAXN];

ll A,B;

ll DP[MAXN][MAXN] = {0};
bool DPC[MAXN][MAXN] = {0};

ll dp(ll i, ll rp){
    if(i == n)return 0;
    if(DPC[i][rp])return DP[i][rp];
    ll ans = 0;
    if(P2[i] < rp){
        ans = A + dp(i+1, rp);
    }
    else{
        ans = min(B + dp(i+1, rp), dp(i+1, P2[i]));
    }
    DP[i][rp] = ans;
    DPC[i][rp] = 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> A >> B;

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        a--;
        P[c1] = a;
        P2[a] = c1;
    }

    a = dp(0,0);
    cout << a << "\n";

    return 0;
}
