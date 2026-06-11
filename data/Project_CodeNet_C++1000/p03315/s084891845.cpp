#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int ans=0;
    rep(i, s.size()) {
        if (s[i] == '+') ans++;
        else ans--;
    }
    cout << ans << endl;
    return 0;
}