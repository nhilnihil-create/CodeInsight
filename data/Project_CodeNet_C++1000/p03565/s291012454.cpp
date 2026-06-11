#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

string s, t;
int S;
int T;

bool match(int k) {
    rep(i, T) {
        if(t[i] != s[i + k] && s[i + k] != '?') {
            return false;
        }
    }
    return true;
}

string construct (int k) {
    string ans = s;
    rep(i, T) {
        ans[k + i] = t[i];
    }
    rep(i, S) {
        if(ans[i] == '?') ans[i] = 'a';
    }
    return ans;
}

int main()
{
    cin >> s >> t;
    S = s.size();
    T = t.size();
    vector<string> ans;
    rep(k, S - T + 1) {
        if(match(k)) {
            ans.push_back(construct(k));
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size() == 0) {
        cout << "UNRESTORABLE" << endl;
    }
    else cout << ans[0] << endl;
    return 0;
}
