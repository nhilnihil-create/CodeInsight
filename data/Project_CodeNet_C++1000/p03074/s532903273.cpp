#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    vector<ll> v;
    v.push_back(0);
    if (s[0] == '0')
        v.push_back(0);

    ll seq = 1;
    rep(i, s.size() - 1) {
        if (s[i] == s[i + 1])
            seq++;
        else
            v.push_back(seq), seq = 1;
    }
    v.push_back(seq);

    rep(i, v.size()) { v[i + 1] += v[i]; }

    ll ans = 0;
    for (int i = 0; i < v.size(); i += 2) {
        int right = i + 2 * K + 1;
        if (right >= v.size())
            right = v.size() - 1;
        ans = max(ans, v[right] - v[i]);
    }

    cout << ans << endl;
}