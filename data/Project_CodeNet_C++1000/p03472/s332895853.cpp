#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define int long long int
#define double long double
#define inf (int)(1e15)
#define all(x) (x).begin(), (x).end()
#define pair pair<int, int>
typedef vector<int> vi;   // Vector of long long
typedef vector<vi> vvi;   // Vector of vi
typedef vector<pair> vii; // Vector of pairs
typedef vector<vii> vvii; // Vector of Vector of pairs
typedef vector<bool> vb;  // Vector of bool
#define pq priority_queue // Max heap (To convert to min heap, use negative sign before every value)
#define ff first          // For pairs
#define ss second
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, -1, 0, 1};
const int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}, dy8[] = {1, -1, 1, 0, -1, 1, -0, -1};
#define testcases(t) \
    int(t);          \
    cin >> (t);      \
    while ((t)--)
bool cmp(int a, int b)
{
    return a > b;
}
signed main()
{
    int n, h, amax = -1, thrown = 0, ans = inf, moves;
    cin >> n >> h;
    vi a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        amax = max(amax, a[i]);
    }
    sort(b.begin(), b.end(), cmp);
    b.insert(b.begin(), 0);
    for (int i = 0; i <= n; i++)
    {
        h = h - b[i];
        if (i != 0)
            thrown++;
        if (h < 0)
            moves = thrown;
        else
        {
            moves = (h / amax);
            if (h % amax != 0)
                moves++;
            moves += thrown;
        }
        ans = min(ans, moves);
        // cout << b[i] << " " << h << " " << moves << endl;
    }
    cout << ans << endl;
    return 0;
}