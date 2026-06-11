#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int b = 0, w = 0;

    rep(i, n) {
        if (s[i] == '#') {
            b++;
        } else {
            w++;
        }
    }
    int num = min(b, w);

    b = 0;
    rep(i, n) {
        if (s[i] == '.') {
            w--;
        } else {
            b++;
        }

        num = min(num, b + w);
    }

    cout << num << endl;
}