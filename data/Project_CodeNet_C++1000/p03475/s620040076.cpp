#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); ++i)

void solve(void)
{
    int n;
    cin >> n;

    vector<int> c(n - 1), s(n - 1), f(n - 1);
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
    rep(i, n)
    {
        int time = 0;
        for (int j = i; j < n - 1; ++j)
        {
            if (time < s[j])
                time = s[j];
            else if (time % f[j] != 0)
                time += f[j] - time % f[j];
            time += c[j];
        }
        cout << time << endl;
    }
}
int main(void) { solve(); }
