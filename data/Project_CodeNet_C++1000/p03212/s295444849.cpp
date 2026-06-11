#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dxx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }, dyy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

ll n;
int s[3] = { 3, 5, 7 };
int cnt = 0;
void dfs (int cnt3, int cnt5, int cnt7, ll now) {
    if (now > n) return;
    if (cnt3 > 0 && cnt5 > 0 && cnt7 > 0) {
        cnt++;
        //cout << now << "\n";
    }

    dfs (cnt3 + 1, cnt5, cnt7, now * 10 + 3);
    dfs (cnt3, cnt5 + 1, cnt7, now * 10 + 5);
    dfs (cnt3, cnt5, cnt7 + 1, now * 10 + 7);
}

int main() {
    cin >> n;
    dfs (0, 0, 0, (ll)0);
    cout << cnt << "\n";
}