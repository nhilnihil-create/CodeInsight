#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    string ans;
    for (int i = 0; i < s.size(); i += n) {
        ans.push_back(s[i]);
    }
    cout << ans << endl;
}