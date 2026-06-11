#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    vector<string> s_enda;
    vector<string> s_beginb;
    vector<string> s_endabeginb;
    int ans = 0;
    rep(i, n) {
        string tmp_s;
        cin >> tmp_s;
        rep(j, tmp_s.length()-1) {
            if ( tmp_s[j] == 'A' && tmp_s[j+1] == 'B' ) ++ans;
        }
        if ( tmp_s[tmp_s.length()-1] == 'A' && tmp_s[0] == 'B' ) {
            s_endabeginb.push_back(tmp_s);
        }
        else if ( tmp_s[tmp_s.length()-1] == 'A') s_enda.push_back(tmp_s);
        else if ( tmp_s[0] == 'B' ) s_beginb.push_back(tmp_s);
    }
    int endanum = s_enda.size();
    int beginbnum = s_beginb.size();
    if ( s_endabeginb.size() > 0 ) {
        if ( endanum > 0 ) {
            ++ans;
            --endanum;
        }
        if ( beginbnum > 0 ) {
            ++ans;
            --beginbnum;
        }
    }
    int endabeginbnum = s_endabeginb.size();
    if ( endabeginbnum > 0 ) {
        --endabeginbnum;
    }
    cout << ans + endabeginbnum + min(endanum, beginbnum) << endl;
    return 0;
}
