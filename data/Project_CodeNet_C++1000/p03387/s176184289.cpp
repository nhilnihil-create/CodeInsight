#include <bits/stdc++.h>
#define ll long long int
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define deb(x) cout << #x << " " << x << endl;
#define rep(i, n) for (i = 0; i < n; i++)
#define Rep(i, k, n) for (i = k; i < n; i++)
#define write(x) cout << x << " ";
#define writeLine(x) cout << x << endl;
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ppi pair<int, int>
using namespace std;

int main()
{
    fast;

#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    int ans = a[2] - a[1];
    a[0] = a[0] + ans;
    ans += (a[2] - a[0] + 1) / 2;
    if ((a[2] - a[0]) % 2 == 1)
    {
        ans++;
    }
    cout << ans << endl;
}
