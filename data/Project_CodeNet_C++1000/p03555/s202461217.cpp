#include <bits/stdc++.h>
using namespace std;

struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))
#define int long long

signed main(){
    string s, t;
    cin >> s >> t;
    bool ans = s[0]==t[2] && s[1]==t[1] && s[2]==t[0];
    cout << (ans ? "YES" : "NO") << endl;
}