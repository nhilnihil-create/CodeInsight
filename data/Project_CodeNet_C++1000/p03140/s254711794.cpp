#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;
const int mod = 1e9 + 7;
int main() {

    int n;
    cin >> n;
    string s[3];
    rep(i, 3){
        cin >> s[i];
    }

    int ans = 0;
    rep(i, n){
        set<char> c;
        c.insert(s[0][i]);
        c.insert(s[1][i]);
        c.insert(s[2][i]);
        ans += c.size() - 1;
    }
    cout << ans << endl;
    
    return 0;
}