#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

vector<ll> calc_divisor(ll n) {
    vector<ll> res;
    for (ll i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            ll j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

ll N;
map<ll, ll> mp;

int main() {
    cin >> N;

    // 素因数分解から約数を求める方針
    for (int i = 1; i <= N; i++) {
        vector<pair<ll, ll>> tmp = prime_factorize(i);

        rep(j, tmp.size()) {
            mp[tmp[j].first] += tmp[j].second;
        }
    }

    // 全列挙は無理なので、約数の数が75になる数を探す
    // N=100で、約数の数: 1621986508800 
    // 75 = 3 * 5 * 5
    // debug
    ll a = 1;
    ll a1 = 0; // 素因数が 3つ以上ある 2以上
    ll a2 = 0; // 素因数が 5つ以上ある 4以上

    ll a4 = 0;

    ll b15 = 0; 
    ll b25 = 0; 
    ll b75 = 0; 
    for (auto m : mp) {
        // cout << m.first << " " << m.second << endl;
        if (m.second + 1 >= 3) {
            a1++;
        }
        if ((m.second + 1) >= 5) {
            a2++;
        }

        if ((m.second + 1) >= 15) b15++;
        if ((m.second + 1) >= 25) b25++;
        if ((m.second + 1) >= 75) b75++;
    }


    // 3 * 5 * 5 
    // 5を選ぶ選択肢
    // a2 c 2
    ll ans_5 = a2 * (a2 - 1) / 2;
    // cout << ans << endl;
    // 3を選ぶ選択肢 (a1 - 2) C 1
    ll ans_3 = (a1 - 2);

    ll ans = ans_5 * ans_3;

    // 5 * 15
    ll ans2 = b15 * (a2 - 1);
    ans += ans2;

    // 3 * 25
    ll ans3 = b25 * (a1 - 1);
    ans += ans3;

    // 1 * 75
    ll ans4 = b75;
    ans += ans4;
    // cout << ans4 << endl;

    cout << ans << endl;
}