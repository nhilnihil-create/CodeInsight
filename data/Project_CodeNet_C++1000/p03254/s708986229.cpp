#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &&e : a)
        cin >> e;
    sort(a.begin(), a.end());
    int ans = 0;
    for (const auto e : a) {
        if (x >= e) {
            ++ans;
            x -= e;
        } else
            break;
    }
    if (ans == n && x != 0)
        --ans;
    cout << ans << '\n';
}