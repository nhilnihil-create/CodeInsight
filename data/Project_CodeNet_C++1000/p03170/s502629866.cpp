#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define ll long long int



int main()
{
    fast_io;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<bool> dp(k+1);
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; a[j] <= i && j < a.size(); j++)
        {
            if(a[j] == i)
            {
                dp[i] = true;
                break;
            }
            if(dp[i - a[j]] == false)
            {
                dp[i] = true;
                break;
            }
        }
    }
    if(dp[k])
        cout << "First";
    else
        cout << "Second";
    return 0;
}
