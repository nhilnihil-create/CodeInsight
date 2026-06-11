#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}
 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n, 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    ll min_diff = 10000000000;
    for (size_t i = 0; i <= n - k; i++)
    {
        int diff = h[i + k - 1] - h[i];
        if (diff < min_diff)
        {
            min_diff = diff;
        }
    }
    cout << min_diff << endl;
 
    return 0;
}