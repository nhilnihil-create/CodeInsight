
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main()
{
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> t(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        t[a]++;
    }

    int right = 0;

    for (int i = x; i < n; i++)
    {
        right += t[i];
    }

    int left = 0;
    for (int i = x; i > 0; i--)
    {
        left += t[i];
    }

    cout << min(left, right) << endl;
}