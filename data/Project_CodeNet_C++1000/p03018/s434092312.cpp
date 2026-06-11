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
    string S;
    cin >> S;
    int n = S.size();
    int s[n] = {};
    ll ans = 0;
    per (i, 0, n - 1) {
        if (S[i] == 'B' && S[i + 1] == 'C') {
            if (i + 2 < n) s[i + 1] = s[i + 2];
            s[i] = s[i + 1] + 1;
        } else if (S[i] == 'A') {
            s[i] = s[i + 1];
            ans += s[i];
        }
    }
    // rep (i, 0, n) cout << s[i] << " ";
    cout << ans << "\n";
}