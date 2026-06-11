#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // AtCoder
    // template
    string s;
    cin >> s;
    ll sum = 0;
    for(auto &&i : s) {
        sum += i - '0';
    }
    cout << max((int)sum, (int)(s.size() - 1) * 9 + s[0] - '0' - 1) << endl;
}
