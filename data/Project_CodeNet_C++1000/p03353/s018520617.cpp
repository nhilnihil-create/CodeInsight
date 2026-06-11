#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
#define PRYES(x) PR((x) ? "Yes" : "No")
const long long INF = numeric_limits<long long>::max();

template <class T> void dumpVector(const vector<T>& vec) {
#ifdef SOURCE_TEST
    for (ll i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ",";
    }
    cout << endl;
#endif
}

template <class T> void distinct(vector<T>& vec) {
    // 配列から重複を削除する
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

int main() {
    string s;
    cin >> s;
    ll N;
    cin >> N;

    vector<string> strings;
    for (ll i = 0; i < s.size(); ++i) {
        for (ll j = 1; (i + j) <= s.size(); ++j) {
            if (j > 5) continue;
            strings.push_back(s.substr(i, j));
        }
    }

    dumpVector(strings);
    sort(strings.begin(), strings.end());
    distinct(strings);

    PR(strings[N - 1]);
    return 0;
}