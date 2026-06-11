#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> q(n);
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        q[l - 1]++;
        if (r < n)
        {

            q[r]--;
        }
    }
    int ct = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        q[i + 1] += q[i];
        if (q[i] == m)
        {
            ++ct;
        }
    }
    cout << (q[n - 1] == m ? ct + 1 : ct) << endl;
}