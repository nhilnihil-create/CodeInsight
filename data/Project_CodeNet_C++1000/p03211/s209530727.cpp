// う　し　た　ぷ　に　き　あ　く　ん　笑
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long
constexpr int M = 3;
constexpr int LOVE = 753;
constexpr int INF = 1000000000 + 8;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    const int n = s.size();

    int ans = INF;

    for (int i = 0; i < n - M + 1; i++) {
        const string ss = s.substr(i, M);
        const int x = stoi(ss);
        const int xx = abs(x - LOVE);
        ans = min(xx, ans);
    }

    cout << ans << endl;
}
