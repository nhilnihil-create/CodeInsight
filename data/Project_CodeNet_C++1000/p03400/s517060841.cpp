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

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int eat = 0;
    for (auto &&i : a) {
        eat += (d - 1) / i + 1;
    }

    cout << eat + x << endl;
}
