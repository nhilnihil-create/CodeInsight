#include <bits/stdc++.h>
using namespace std;

#define VIC ios::sync_with_stdio(0);cin.tie(0);ios_base::sync_with_stdio(0);
#define wtf(s) freopen((s), "w", stdout)
#define rff(s) freopen((s), "r", stdin)
#define pi (2 * acos(0))
typedef long double ld;
typedef long long ll;
typedef complex<ld> point;
#define endl '\n'
#define matrix vector<vector<ll>>
#define EPS 1e-9
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define dot(a, b) ((conj(a) * (b)).real())
#define cross(a, b) ((conj(a) *(b)).imag())
#define lengthsqr(v) (dot(v, v))
#define length(v) ((ld)hypot((v).Y, (v).X))
#define same(a, b) (lengthsqr(vec(a, b)) < EPS)

const int N = 1e5 + 5, inf = 1e9 + 5;
const ll mod = 1e9 + 7;

int ans = -inf, n, val[102][12];
bool a[102][12];

int calc(vector<int>& v)
{
    int cnt[102] = {};
    for (auto it: v)
        for (int j = 0; j < n; j++)
            if (a[j][it])
                cnt[j]++;
    int tot = 0;
    bool good = false;
    for (int i = 0; i < n; i++)
        good |= cnt[i] > 0,
        tot += val[i][cnt[i]];
    if (!good)
        tot = -inf;
    return tot;
}

void solve(int i, vector<int>& v)
{
    if (i == 10)
    {
        ans = max(ans, calc(v));
        return;
    }
    v.push_back(i);
    solve(i + 1, v);
    v.pop_back();
    solve(i + 1, v);
}

int main()
{
    VIC
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 11; j++)
            cin >> val[i][j];
    }
    vector<int> v;
    solve(0, v);
    cout << ans;
    return 0;
}
