#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
bool isOK(int index, string key) {
    string res;
    if(index % 2 == 0) {
        if(key == "Female") {
            res = "Male";
        } else {
            res = "Female";
        }
    } else {
        res = key;
    }
    cout << index << endl;

    string pon;
    cin >> pon;
    if(pon == "Vacant") {
        cout << index << endl;
        exit(0);
    }
    if(pon == res) {
        return true;
    } else
        return false;
}
int N;
// 汎用的な二分探索のテンプレ
ll binary_search(string key) {
    ll ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = N; // 「index =
               // a.size()-1」が条件を満たさないこともあるので、初期値は
               // a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while(abs(ok - ng) > 1LL) {
        ll mid = (ok + ng) / 2LL;

        if(isOK(mid, key))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    cin >> N;
    cout << 0 << endl;
    string hoge;
    cin >> hoge;
    if(hoge == "Vacant") {
        cout << 0 << endl;
        return 0;
    }
    binary_search(hoge);
    return 0;
}