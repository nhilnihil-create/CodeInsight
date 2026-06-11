//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    string s, t;
    cin >> s >> t;
    int num = s.size();
    vi si(num), ti(num);
    rep(i, num) {
        si[i] = s[i] - 'a';
        ti[i] = t[i] - 'a';
    }

    vi sc(26), tc(26);
    
    rep(i, num) {
        ++sc[si[i]];
        ++tc[ti[i]];
    }

    sort(sc.begin(), sc.end());
    sort(tc.begin(), tc.end());

    rep(i, 26) {
        if(sc[i]-tc[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}