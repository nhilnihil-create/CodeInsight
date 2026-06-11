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
    string s;
    string t;
    cin>>s>>t;
    ll n=s.size();
    ll m=t.size();
    ll dp[n+1][m+1];
    for (int i = 0; i <=n ; ++i) {
        for (int j = 0; j <=m ; ++j) {
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    char lcs[dp[n][m]];
    ll index=dp[n][m];
    if(index==0){
        cout<<" "<<"\n";
        return 0;
    }
    ll i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            lcs[index-1]=s[i-1];
            i--;j--;index--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) {
            i--;
        }
        else
            j--;
    }
    for(auto u:lcs)
        cout<<u;
    return 0;
}
