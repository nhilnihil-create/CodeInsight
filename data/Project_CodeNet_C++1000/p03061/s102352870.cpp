#include <bits/stdc++.h>
#define lli long long int
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
    int n;
    cin >> n;
    vector<lli> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<lli> left(n);
    vector<lli> right(n);

    left[0] = a[0];
    right[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = __gcd(left[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = __gcd(right[i + 1], a[i]);
    }

    lli ans = left[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        ans = max(ans, __gcd(left[i - 1], right[i + 1]));
    }
    ans = max(ans, left[n - 2]);
    ans = max(ans, right[1]);
    cout << ans << endl;
}
