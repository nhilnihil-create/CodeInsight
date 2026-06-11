#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

//For nCk
const int MAX = 5100000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
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
int main() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, n){
        cin >> a.at(i);
    }

    vector<ll> dif;
    dif.push_back(0);

    rep(i, n){
        ll tmp = dif.at(i);
        tmp += a.at(i);
        tmp %= m;
        dif.push_back(tmp);
    }

    int now = 0;
    ll cnt = 0;
    map<ll, ll> mp;
    for(int i=0; i<=n; i++){
        mp[dif.at(i)]++;
    }

    for(auto x:mp){
        cnt += (x.second*(x.second-1))/2LL;
    }

    cout << cnt << endl;

    return 0;
}
