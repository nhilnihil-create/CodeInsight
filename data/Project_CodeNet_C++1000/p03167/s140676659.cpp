//subset sum problem

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long int ll;
typedef unsigned long long int ull;
#define fi first
#define se second
#define pb push_back
ll mod1=pow(10,9)+7;
int mod2=998244353;
ll inf=1e9;
ll maxxy=1e6+9;
typedef long double ld;
const double PI =  3.141592653589793238;

ll power(ll x, ll y, ll pp)
{
    ll res = 1;
    x = x % pp;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % pp;
        y = y>>1;
        x = (x*x) % pp;
    }
    return res;
}

ll modInverse(ll n, ll pp)
{
    return power(n, pp-2, pp);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w;
    cin>>h>>w;
    char a[h][w];
    int dp[h][w];
    for (int i = 0; i <h ; ++i) {
        for (int j = 0; j <w ; ++j) {
            cin>>a[i][j];
        }
    }
    for (int i = 0; i <h ; ++i) {
        for (int j = 0; j <w ; ++j) {
            if(a[i][j]=='#'){
                dp[i][j]=0;
            }
            else{
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=0;
                    if(i-1>=0) {
                        dp[i][j] += dp[i - 1][j];
                        dp[i][j] %= mod1;
                    }
                    if(j-1>=0) {
                        dp[i][j] += dp[i][j - 1];
                        dp[i][j] %= mod1;
                    }
                }
            }
        }
    }
    cout<<dp[h-1][w-1]<<"\n";
    return 0;
}
