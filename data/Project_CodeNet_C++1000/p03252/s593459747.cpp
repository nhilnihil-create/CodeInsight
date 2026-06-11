#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    string s, t;
    cin >> s >> t;

    vector<int> trans(26, -1), rev_trans(26, -1);
    bool flg = true;
    for (auto i = 0; i < (int)s.size(); i++) {
        if(trans[s[i] - 'a'] < 0) trans[s[i] - 'a'] = t[i] - 'a';
        else if(trans[s[i] - 'a'] != t[i] - 'a') { flg = false; break; }
        if(rev_trans[t[i] - 'a'] < 0) rev_trans[t[i] - 'a'] = s[i] - 'a';
        else if(rev_trans[t[i] - 'a'] != s[i] - 'a') { flg = false; break; }
    }

    cout << ((flg) ? "Yes" : "No") << endl;
    return 0;
}