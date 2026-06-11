#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    string s;
    cin >> s;
    int win = 0;
    rep(i, s.length()) {
        if ( s[i] == 'o' ) ++win;
    }
    if ( win + 15 - s.length() >= 8 ) cout << "YES" << endl;
    else                              cout << "NO" << endl;
    return 0;
}
