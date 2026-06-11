
#include <bits/stdc++.h>

using namespace std;

#define rep(i, x)   for (__typeof(x) i = 0; i < x; i++)
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define repi(i, x)  for (__typeof(x) i = x-1; i >= 0; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
typedef vector<vector<int> > vvi;
typedef pair<ll, ll>   pairl;
typedef vector<ll>     vl;
typedef vector<ll>     vll;
typedef vector<vector<ll> > vvl;
const   int            infi = numeric_limits<int>::max();
const   ll             infl = numeric_limits<ll>::max();
const   double         eps = 0;
const   int            ms  = 0;


long long fac[300001], finv[300001], inv[300001];
const int MOD = 998244353;

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 300001; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);//endl->"\n"
    cin.tie(0);
    ll N, A, B, K;
    cin >> N >> A >> B >> K;
    COMinit();
    ll ans = 0;
    for(ll i = 0; i*A <= K; i++){
        if( (K-i*A) % B != 0){
            continue;
        }
        ll j = (K-i*A)/B;
        ans = (ans + (COM(N, i)*COM(N, j))%MOD)%MOD;
    }
    cout << ans << "\n";
    return 0;
}