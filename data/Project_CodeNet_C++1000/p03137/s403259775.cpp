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
signed main()
{
    int n, m;
    cin >> n >> m;
    int x[m];
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }
    sort(x, x + m);
    if (n >= m)
        cout << 0 << endl;
    else
    {
        int dif[m], sum = 0;
        for (int i = 1; i < m; i++)
        {
            dif[i - 1] = x[i] - x[i - 1];
        }
        sort(dif, dif + m - 1);
        for (int i = 0; i < (m - n); i++)
        {
            sum += dif[i];
        }
        cout << sum << endl;
    }
    return 0;
}