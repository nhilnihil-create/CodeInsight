#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

bool check(const vector<string>& vs, int d) {
    int n = vs.size();
    rep(y, n) rep(x, n) {
        int x1 = (x + d) % n;
        int x2 = (y + d) % n;
        if (vs[y][x1] != vs[x][x2]) return false;
    }
    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<string> vs(n);
    rep(i, n) cin >> vs[i];

    int ans = 0;
    rep(i, n) {
        if (check(vs, i)) ans += n;
    }

    cout << ans << endl;

    return 0;
}
