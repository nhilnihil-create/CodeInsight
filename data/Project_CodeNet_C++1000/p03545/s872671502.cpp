#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int x;
    cin >> x;
    int a = x / 1000, b = (x % 1000) / 100, c = (x % 100) / 10, d = (x % 10);
    vector<int> vec;
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(d);
    rep(i, 0, 1 << 3) {
        int sum = a;
        rep(j, 0, 3) {
            if (i & 1 << j) {
                sum += vec[j];
            } else {
                sum -= vec[j];
            }
        }
        if (sum == 7) {
            cout << a;
            rep(j, 0, 3) {
                if (i & 1 << j) {
                    cout << "+";
                } else {
                    cout << "-";
                }
                cout << vec[j];
            }
            cout << "=7\n";
            return 0;
        }
    }
}