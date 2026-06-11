#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    string s;
    cin >> s;

    int ans = 0;
    if (s[0] == '1') ans++;
    if (s[1] == '1') ans++;
    if (s[2] == '1') ans++;

    cout << ans << endl;
    return 0;
}