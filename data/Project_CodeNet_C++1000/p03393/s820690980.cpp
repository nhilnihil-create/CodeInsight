#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    string s; cin >> s;
    vector<string> ans;
    string c = "abcdefghijklmnopqrstuvwxyz";
    set<char> se;
    rep(i,26) se.insert(c[i]);
    rep(i,s.size()) se.erase(s[i]);
    if (s.size() <= 25) ans.push_back(s + *se.begin());
    string ss = s;
    if (next_permutation(ss.begin(), ss.end())) {
        ans.push_back(ss);
    }
    for (int i=s.size()-1; i>=0; i--) {
        se.insert(s[i]);
        auto it = se.upper_bound(s[i]);
        if (it != se.end()) {
            ans.push_back(s.substr(0,i) + *it);
        }
    }
    sort(ans.begin(), ans.end());
    //rep(i,ans.size()) cout << ans[i] << endl;
    if (ans.size() == 0) cout << -1 << endl;
    else cout << ans.front() << endl;
}