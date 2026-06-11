#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll>PLL;
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll MOD = 1e4+7;
int main() {
    string s;
    cin >> s;
    set<string> st;
    string t = "AKIHABARA";
    rep(i, 1<<9) {
        string x;
        rep(j, 9) {
            if ( (i>>j)&1 ) {
                x += t[j];
            }
            else if ( t[j] != 'A' ) {
                x = "x";
            }
        }
        st.insert(x);
    }
    printf(st.count(s)?"YES":"NO");
    return 0;
}
