#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    if (n >= 2)
    {
        cout << max(abs(v[n - 1] - w), abs(v[n - 1] - v[n - 2]));
    }
    else
    {
        cout << abs(v[0] - w) << endl;
    }
}