#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;  cin >> N >> K;
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        int a;  cin >> a;
        ++mp[a];
    }
    vector<int> v;
    for (auto e : mp) v.push_back(e.second);
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < (int)v.size() - K; ++i) ans += v[i];
    cout << ans << endl;
}
