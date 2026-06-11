#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    string s;
    cin >> s;
    string ans;
    cout << s[0];
    rep (bit, 0, 1 << 3) {
        int sum = s[0] - '0';
        rep (i, 0, 3) {
            if (bit & 1 << i) {
                sum += s[i + 1] - '0';
            } else {
                sum -= s[i + 1] - '0';
            }
        }
        if (sum == 7) {
            rep (i, 0, 3) {
                if (bit & 1 << i) {
                    cout << '+';
                } else {
                    cout << '-';
                }
                cout << s[i + 1];
            }
            cout << "=7\n";
            return 0;
        }
    }
}