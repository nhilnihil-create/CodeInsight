#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;  cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        int a;  cin >> a;
        ++mp[a];
    }
    int ans = 0;
    for (auto e : mp) {
        if (e.second > e.first) ans += e.second - e.first;
        else if (e.second < e.first) ans += e.second;
    }
    cout << ans << endl;
}
