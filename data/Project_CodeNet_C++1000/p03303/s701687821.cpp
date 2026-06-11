#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s, ans;

    cin >> s >> t;

    int cnt = t;

    for(int i = 0; i < s.size(); ++i) {
        if(cnt == t) {
            ans.push_back(s[i]);
            cnt = 0;
        }
        ++cnt;
    }

    cout << ans << endl;
    return 0;
}