#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int w;
    string s;

    cin >> s;
    cin >> w;

    string ans;

    for (int i = 0; i < s.size(); i += w) {
        ans.push_back(s.at(i));
    }

    cout << ans << endl;
}