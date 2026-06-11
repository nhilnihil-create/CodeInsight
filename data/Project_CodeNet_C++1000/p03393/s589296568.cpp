#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    bool flg[26] = {0};
    set<char> st;
    rep(i, s.length()) {
        flg[s[i]-'a'] = 1;
        st.insert(s[i]);
    }
    if ( st.size() != 26 ) {
        rep(i, 26) {
            if ( !flg[i] ) {
                s += (char)(i + 'a');
                break;
            }
        }
    }
    else {
        bool ng = 1;
        for ( int i = s.length() - 1; i >= 1; --i ) {
            char tmp_char;
            if ( s[i] > s[i-1] ) {
                flg[s[i]-'a'] = 0;
//                rep(j, 26) {
//                    cout << flg[j] << " ";
//                }
//                cout << endl;
                tmp_char = (char)(s[i-1] + 1 );
                while(1) {
//                    cout << tmp_s << endl;
                    if ( tmp_char > 'z' ) {
                        break;
                    }
                    if ( !flg[tmp_char-'a'] ) {
                        s = s.substr(0, i-1) + tmp_char;
                        ng = 0;
                        break;
                    }
                    ++tmp_char;
                }
            }
//            cout << ng << endl;
            if ( ng == 0 ) {
                break;
            }
            flg[s[i]-'a'] = 0;
        } 
        if ( ng ) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << s << endl;
    return 0;
}