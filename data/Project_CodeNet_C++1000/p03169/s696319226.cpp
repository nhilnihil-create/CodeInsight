#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
#define X real()
#define Y imag()
#define EPS 1e-6
#define pi acos(-1)
#define vec(a,b) (b)-(a)
#define ec_norm(a) (a).X*(a).X+(a).Y*(a).Y
#define norm(a) hypot((a).X,(a).Y)
#define angle(a) atan2((a).Y,(a).X)
#define dot(a,b) (conj(a)*(b)).X
#define cross(a,b) (conj(a)*(b)).Y
#define rotate(a,b,ang) ((b)-(a))*exp(point(0,(ang)))+(a)
#define reflect(p,a,b) conj(((p)-(a))/((b)-(a)))*((b)-(a))+(a)
typedef complex<ld> point;
const int A = 3e2 + 2;
const int mod = 1e9 + 7;
int n;
ld dp[A][A][A];
bool vis[A][A][A];
ld solve(int c1, int c2, int c3) {
    int c0 = n - c1 - c2 - c3;
    if (c0 == n) return 0;
    if (vis[c1][c2][c3])
        return dp[c1][c2][c3];
    vis[c1][c2][c3] = 1;
    ld val = 1;
    if (c1)
        val += solve(c1 - 1, c2, c3) * (c1 / (n * 1.0));
    if (c2)
        val += solve(c1 + 1, c2 - 1, c3) * (c2 / (n * 1.0));
    if (c3)
        val += solve(c1, c2 + 1, c3 - 1) * (c3 / (n * 1.0));
    val /= (1.0 - c0 / (n * 1.0));
    return dp[c1][c2][c3] = val;
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    int freq[3] = {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x - 1]++;
    }
    cout << setprecision(9) << fixed << solve(freq[0], freq[1], freq[2]);
    return 0;
}