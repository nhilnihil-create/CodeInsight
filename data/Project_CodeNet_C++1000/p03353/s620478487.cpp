#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for (int i = 0; i < (n); ++i)
int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> substring;
    int s_len = s.length();
    rep(i, s.length()) {
        for ( int j = 1; j <= min(k, s_len - i); j++ ) {
//            bool break_flg = false;
//            rep(k, substring.size()) {
//                if ( substring[k] == s.substr(i, j) ) {
//                    break_flg = true;
//                    break;
//                }
//            }
//            if ( !break_flg ) substring.push_back(s.substr(i, j));
            substring.push_back(s.substr(i, j));
        }
    }
    sort(substring.begin(), substring.end());
    substring.erase(unique(substring.begin(), substring.end()), substring.end());
//    rep(i, substring.size()) cout << substring[i] << endl;
    cout << substring[k-1] << endl;
    return 0;
}