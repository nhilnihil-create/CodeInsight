#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,x,n) for(ll i=x;i<n;i++)
#define S(v) sort(v.begin(), v.end())
#define print(v) for(auto i:v)cout<<i<<" "
const ll N = 1e5 + 7;
ll dp[N][3], a[N][3];

ll f(ll i, ll n, ll x){
    if(dp[i][x] != -1){
        return dp[i][x];
    }
    if(i != n-1){
        if(x == 0){
            dp[i][x] = a[i][x] + max(f(i+1, n, 1), f(i+1, n, 2));
            return dp[i][x];
        }
        else if(x == 1){
            dp[i][x] = a[i][x] + max(f(i+1, n, 0), f(i+1, n, 2));
            return dp[i][x];
        }
        else{
            dp[i][x] = a[i][x] + max(f(i+1, n, 1), f(i+1, n, 0));
            return dp[i][x];
        }
    }
    else {
        if(x == 0){
            dp[i][x] = a[i][x];
            return dp[i][x];
        }
        else if(x == 1){
            dp[i][x] = a[i][x];
            return dp[i][x];
        }
        else{
            dp[i][x] = a[i][x];
            return dp[i][x];
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
    ll n;
    cin>>n;
    loop(i,0,n){
        loop(j,0,3){
            cin>>a[i][j];
            dp[i][j] = -1;
        }
    }    
    cout<<max(f(0, n, 0),max(f(0, n, 1), f(0, n, 2)));
} 