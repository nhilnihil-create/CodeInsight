#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> hs;
#define rep(i, k, n) for (int i = k; i < (int)(n); i++)

int main()
{
    cin >> n;

    rep(i, 0, n)
    {
        int h;
        cin >> h;
        hs.push_back(h);
    }
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(hs[0] - hs[1]);
    rep(i,2,n){
           dp[i] = min(dp[i-1]+abs(hs[i-1]-hs[i]), dp[i-2]+abs(hs[i-2]-hs[i]));
    }
     cout << dp[n-1] << endl;
}