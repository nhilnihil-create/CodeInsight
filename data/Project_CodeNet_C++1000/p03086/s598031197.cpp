//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    rep(i, s.size()) {
        if(s[i] == 'A' || s[i] == 'G'|| s[i] == 'C' || s[i] == 'T') {
            cnt++;
            ans = max(cnt, ans);
        }else {
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
