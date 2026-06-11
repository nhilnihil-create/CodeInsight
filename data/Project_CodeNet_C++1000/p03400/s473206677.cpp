#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a, b, c, m, n, ans;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b;
    vi A(n);
    rep(i, n) cin >> A[i];
    int count = n;
    rep(i, n)
        count += (a - 1) / A[i];

    cout << count + b << endl;

    return 0;
}