#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> inline bool chmin(T &a, T b)
{
    if(a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    int INF = 1<<30;
    vector<int> dp(N+1, INF);
    dp[0] = 0;
    for(int i=0; i<N; i++)
    {
        chmin(dp[i+1], dp[i]+1);
        for(int j=6; i+j<=N; j*=6)
        {
            chmin(dp[i+j], dp[i]+1);
        }
        for(int j=9; i+j<=N; j*=9)
        {
            chmin(dp[i+j], dp[i]+1);
        }
    }
    cout << dp[N] << endl;

    return 0;
}
