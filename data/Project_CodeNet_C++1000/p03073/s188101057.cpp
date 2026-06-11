#include <iostream>
#include <string>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = s.size();
    rep(i, 2) {
        int cnt = 0;
        rep(j, s.size()) {
            if ((j % 2 == 0) ^ (s[j] != (char)(i + '0'))) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}