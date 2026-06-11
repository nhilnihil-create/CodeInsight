#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

const int MOD = 1e9 + 7;
const int MAXV = 1e5;

int main() {
    FAST_IO();
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    C = 2*C;
    A = min(A, C);
    B = min(B, C);
    int ans = 0;
    if(A + B <= C) {
        ans = A * X + B * Y;
    } else {
        int Z = min(X, Y);
        X -= Z;
        Y -= Z;
        ans = A * X + B * Y + C * Z;
    }
    cout << ans << endl;
    return 0;
}