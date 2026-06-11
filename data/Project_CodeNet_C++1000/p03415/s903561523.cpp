#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    V<string> s(3);
    for(int i = 0; i < 3; i++) cin >> s[i];
    string ans = "";
    ans += s[0][0];
    ans += s[1][1];
    ans += s[2][2];
    cout << ans << endl;

    return 0;
}
