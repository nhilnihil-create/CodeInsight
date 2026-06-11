#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define INF 10000000000
#define MOD 1000000007
using namespace std;
int main() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    string s;
    map<char, int> m;
    rep(i, n) {
        if(a[i] == b[i])
            s += a[i];
        else if(b[i] == c[i])
            s += b[i];
        else
            s += c[i];
    }
    int ans = 0;
    rep(i, n) {
        if(a[i] != s[i]) ans++;
        if(b[i] != s[i]) ans++;
        if(c[i] != s[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}