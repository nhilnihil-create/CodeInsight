#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long int

void testcase()
{
    ll n;
    cin >> n;
    ll ar[n], ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    for (int i = 0; i < n; i++)
    {
        if ((ar[i] & 1))
        {
            continue;
        }
        else
        {
            // cout << 1 << "\n";
            while (!(ar[i] & 1))
            {
                ar[i] /= 2;
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}
