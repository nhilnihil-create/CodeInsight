#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int s;
    cin >> s;
    set<int> a;

    int n = s;
    int ans;
    for (int i = 1;; i++) {

        if (a.count(n) == 0) {
             a.insert(n);
        } else {
            ans = i;
            break;
        }

        // making next value
        if(n % 2 == 0) { // even
            n /= 2;
        } else { // odd
            n = 3 * n + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
