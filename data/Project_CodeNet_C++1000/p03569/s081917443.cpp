#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    string s;
    cin >> s;
    int nl = 0, nr = s.size() - 1;
    int ans = 0;
    while (nl < nr) {
        if (s[nl] == s[nr]) {
            nl++, nr--;
        } else if (s[nl] == 'x') {
            nl++;
            ans++;
        } else if (s[nr] == 'x') {
            nr--;
            ans++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << "\n";
}