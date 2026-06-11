#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;


int main() {
    int s;
    cin >> s;

    bool exist[1000001] = {};

    int ai = s, ans = 1;
    while (exist[ai] == false) {
        exist[ai] = true;
        if (ai % 2 == 0) {
            ai = ai / 2;
        } else {
            ai = 3 * ai + 1;
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}