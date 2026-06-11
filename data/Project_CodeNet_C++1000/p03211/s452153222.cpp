#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i=init;i<(n);i++)

int main() {
    string s;
    cin >> s;
    int ans = INF;
    repi(i, s.size() - 2, 0) {
        int num = 0;
        repi(j, i + 3, i) {
            num += pow(10,i - j + 2) * (s[j] - '0');
        }
        ans = min(ans,abs(753 - num));
    }
    cout << ans << endl;
    return 0;
}