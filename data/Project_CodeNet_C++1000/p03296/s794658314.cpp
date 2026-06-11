#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

int a[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    a[n] = 101;

    int s = 0, sol = 0;
    for (int i = 1; i <= n; ++i)
    {
        ++s;
        if (a[i] != a[i-1])
        {
            sol += s / 2;
            s = 0;
        }
    }
    cout << sol;
}
