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
    int n, cnt = 0, c1 = 0, c2 = 0, c3 = 0;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i][0] == 'B' && s[i][s[i].length() - 1] == 'A')
            c1++;
        else if (s[i][0] == 'B')
            c2++;
        else if (s[i][s[i].length() - 1] == 'A')
            c3++;
        for (int j = 0; j < s[i].length() - 1; j++)
        {
            if (s[i][j] == 'A' && s[i][j + 1] == 'B')
                cnt++;
        }
    }
    if (c1 == 0)
    {
        cnt += min(c2, c3);
    }
    else
    {
        if (c2 + c3)
            cnt += (c1 + min(c2, c3));
        else
            cnt += (c1 - 1);
    }
    cout << cnt << endl;
    return 0;
}