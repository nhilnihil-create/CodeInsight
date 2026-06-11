#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

map<int, int> f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int sum = 0;
    ll sol = 0;
    f[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        sum += x;
        sum %= m;
        sol += f[sum];
        f[sum]++;
    }
    cout << sol;
}
