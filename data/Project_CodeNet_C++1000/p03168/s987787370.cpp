#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
#define X real()
#define Y imag()
#define EPS 1e-10
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
const int A = 3e3 + 2;
const int mod = 1e9 + 7;
int n;
ld a[A], dp[A][A];
bool vis[A][A];
ld solve(int ind, int rem) {
    if (ind == n) return !rem;
    if (vis[ind][rem])
        return dp[ind][rem];
    vis[ind][rem] = 1;
    ld ret = solve(ind + 1, rem - 1) * a[ind] + solve(ind + 1, rem) * (1 - a[ind]);
    return dp[ind][rem] = ret;
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ld ans = 0;
    for (int i = n / 2 + 1; i <= n; i++) {
        ans += solve(0, i);
    }
    cout << setprecision(9) << fixed << ans;
    return 0;
}