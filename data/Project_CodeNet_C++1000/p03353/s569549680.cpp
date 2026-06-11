#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    map<string, int> mp;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            mp[s.substr(j, i)]++;
        }
    }
    int cnt = 0;
    for (auto x : mp) {
        cnt++;
        if (cnt == k) {
            cout << x.first << endl;
            return 0;
        }
    }
}