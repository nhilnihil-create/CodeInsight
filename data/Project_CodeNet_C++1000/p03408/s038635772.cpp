#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;
    string s[N];
    rep(i, N) cin >> s[i];

    int M;
    cin >> M;
    string t[M];
    rep(i, M) cin >> t[i];

    map<string, int> m;
    rep(i,N) {
        m[s[i]] = 0;
    }

    rep(i,N) {
        m[s[i]] += 1;
    }

    rep(i,M) {
        m[t[i]] -= 1;
    }

    int ma = 0;

    for (auto kv : m) {
        ma = max(ma, kv.second);
    }

    cout << ma << endl;



    return 0;
}