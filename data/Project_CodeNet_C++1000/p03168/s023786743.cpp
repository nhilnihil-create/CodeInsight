#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define w(x) int x; cin>>x; while(x--)
#define f(i,n) for(ll i=0;i<n;i++)
#define ff first
#define ss second

void ganekasar()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() 
{
    ganekasar();
    
    int n;
    cin>>n;

    vector<double> dp(n+1, 0.0);

    dp[0] = 1;

    for(int coin = 0; coin < n; coin++)
    {
        double p_heads;
        cin>>p_heads;

        for(int i = coin+1; i >= 0; i--)
        {
            if(i == 0)
                dp[i] = dp[i]*(1 - p_heads);
            else
                dp[i] = dp[i-1]*p_heads + dp[i]*(1 - p_heads);
        }
    }

    double answer = 0;

    for(int heads = 0; heads <= n; heads++)
    {
        int tails = n - heads;

        if(heads > tails)
            answer += dp[heads];
    }

    cout<<fixed<<setprecision(10)<<answer<<endl;
    
    return 0; 
} 