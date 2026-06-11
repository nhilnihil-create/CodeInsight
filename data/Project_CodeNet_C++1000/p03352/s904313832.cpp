#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    speed();
    int X; cin >> X;
    int ans = 0;
    if (X == 1) {
        cout << "1";
        exit(0);
    }
    rep(i, 1, 32) {
        rep(j, 2, X) {
            int v = pow(i, j);
            if (v <= X) ans = max(ans, v);
        }
    }
    cout << ans << endl;
    return 0;
}