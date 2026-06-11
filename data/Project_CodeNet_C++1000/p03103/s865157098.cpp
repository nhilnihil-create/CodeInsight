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

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    // shops[i] = {value, stocks}
    vector<pair<int, int>> shops(n);
    for (int i = 0; i < n; i++) {
        shops[i] = {a[i], b[i]};
    }

    sort(shops.begin(), shops.end());

    int drinks_you_buy = m;
    int money = 0;
    for (int i = 0; i < n; i++) {
        if (drinks_you_buy > shops[i].second) {
            drinks_you_buy -= shops[i].second;
            money += shops[i].first * shops[i].second;
        } else {
            money += shops[i].first * drinks_you_buy;
            drinks_you_buy = 0;
            break;
        }
    }

    cout << money << endl;
}
