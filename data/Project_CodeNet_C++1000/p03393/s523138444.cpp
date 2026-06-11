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
#include<numeric>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    bool flg[26] = {0};
    int n = s.length();
    rep(i, n) flg[s[i]-'a'] = 1;
    if ( n != 26 ) {
        cout << s;
        rep(i, 26) {
            if ( flg[i] ) continue;
            cout << (char)(i+'a');
            return 0;
        }
    }

    vector<char> s_v(n);
    rep(i, n) s_v[i] = s[i];
    if ( !next_permutation(s_v.begin(), s_v.end())) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, n) {
        cout << s_v[i];
        if ( s_v[i] != s[i] ) {
            cout << endl;
            return 0;
        }
    }

    return 0;
}
