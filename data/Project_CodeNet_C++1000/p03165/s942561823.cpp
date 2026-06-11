#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef array<ll,2> pll;
const ll NMAX=3005;
ll dp[NMAX][NMAX];
int main()
{
    string a,b;
    cin>>a>>b;
    for(ll i=0;i<a.size();i++){
        for(ll j=0;j<b.size();j++){
            ll cnd=max(dp[i][j+1],dp[i+1][j]);
            if(a[i]==b[j]) cnd=max(cnd,dp[i][j]+1);
            dp[i+1][j+1]=cnd;
        }
    }
    ll x=a.size(),y=b.size();
    string ans;
    while(x>0 && y>0){
        if(a[x-1]==b[y-1]){
            ans.push_back(a[x-1]);
            x--; y--;
        }
        else if(dp[x-1][y]>dp[x][y-1])
            x--;
        else y--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
