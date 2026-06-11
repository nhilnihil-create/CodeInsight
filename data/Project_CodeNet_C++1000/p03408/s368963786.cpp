#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;  cin >> N;
    map<string, int> mp;
    for (int i = 0; i < N; ++i) {
        string s;  cin >> s;
        ++mp[s];
    }
    int M;  cin >> M;
    for (int i = 0; i < M; ++i) {
        string s;  cin >> s;
        --mp[s];
    }

    int ans = -1000000;
    for (auto e : mp) {
        ans = max(ans, e.second);
    }
    cout << max(0, ans) << endl;
}
