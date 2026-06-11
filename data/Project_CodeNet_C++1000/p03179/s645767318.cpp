/*
    author: kartik8800
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x 
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll dp[3001][3001];
void solve(string& s, int n)
{
    dp[n][0] = (s[n-2] == '>' ) ? 1 : 0;
    dp[n][1] = (s[n-2] == '<' ) ? 1 : 0;
    for(int i = n - 1; i >= 2; i--)
    {
        int total = n - i + 1;
        for(int g = 0; g <= total; g++)
        {
            if(g == 0)
            {
                if(i == n)continue;
                dp[i][g] = 0;
                if(s[i-2] == '<' )
                    continue;
                for(int j = 1; j <= total; j++)
                {
                    dp[i][g] = (dp[i][g] + dp[i+1][total-j]) % mod;
                }
            }
            else
            {
                if(s[i-2] == '>')
                     dp[i][g] = (mod + dp[i][g-1] - dp[i+1][g-1]) % mod;
                else
                    dp[i][g] = (dp[i][g-1] + dp[i+1][g-1]) % mod;
            }
        }

    }
}

int main() {
   int n; 
   string s;
   cin >> n;
   cin >> s;

   ll ans = 0;
   solve(s,n);
   for(int gr = n-1; gr >= 0; gr--)
        ans = (ans + dp[2][gr]) % mod;
   cout << ans;
   return 0;
}
