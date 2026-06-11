// https://atcoder.jp/contests/dp/tasks/dp_k
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll n,k;
    cin >> n >> k;
    ll a[n];
    for(int i=0 ; i<n; i++)
        cin >> a[i];
    bool dp[k+1] = {0};
    for(int i=0 ; i<=k ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(i-a[j] >= 0)
                dp[i] = !dp[i-a[j]];
            if(dp[i])
                break;
        }
    }
    /*for(int i=0 ; i<=k ; i++)
        cout << dp[i] << " ";
    cout << endl;*/
    if(dp[k])
        cout << "First\n";
    else
        cout << "Second\n";
    return 0;
}
