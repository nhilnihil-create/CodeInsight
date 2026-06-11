#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 1e3 + 5;
ll x, y, z, k, mx, a[N], b[N], c[N];
vector<ll>tmp, ans;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> x >> y >> z >> k;
    for(int i = 0; i < x; i++)
        cin >> a[i];
    for(int i = 0; i < y; i++)
        cin >> b[i];
    for(int i = 0; i < z; i++)
        cin >> c[i];
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            tmp.push_back(a[i] + b[j]);
    sort(tmp.rbegin(), tmp.rend());
    sort(c, c + z, greater<ll>());
    for(int i = 0; i < min(k, x * y); i++){
        for(int j = 0; j < z; j++)
            ans.push_back(tmp[i] + c[j]);
    }
    sort(ans.rbegin(), ans.rend());
    for(int i = 0; i < k; i++)
        cout << ans[i] << '\n';
    return 0;
}
