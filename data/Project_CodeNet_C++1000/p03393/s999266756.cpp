#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
bool used[27];
int main(){
    string s;
    cin >> s;
    rep(i, (int)s.length()) {
        used[s[i]-'a'] = 1;
    }
    if ( (int)s.length() < 26 ) {
        rep(i, 26) {
            if ( !used[i] ) {
                s += char('a'+i);
                break;
            }
        }
        cout << s << endl;
    }
    else {
        int id = -1;
        for ( int i = (int)s.length()-2; i >= 0; --i ) {
            if ( s[i] < s[i+1] ) {
                id = i;
                break;
            }
        }
        if ( id == -1 ) {
            cout << -1 << endl;
        }
        else {
            string t = s.substr(0, id);
            int idx2 = id + 1;
            for ( int i = id + 1; i < (int)s.length(); ++i ) {
                if ( s[i] < s[idx2]  && s[i] > s[id] ) {
                    idx2 = i;
                }
            }
            t += s[idx2];
            cout << t << endl;
        }
    }
    return 0;
}