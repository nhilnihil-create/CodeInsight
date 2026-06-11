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
    ll n;
    cin>>n;
    vector<double> p(n);
    for (int i = 0; i <n ; ++i) {
        cin>>p[i];
    }
    vector<double> dp(n+1);//dp[i]==there are i heads so far;
    dp[0]=1;
    for (int coins = 0; coins <n ; ++coins) {
        for (int i = coins+1; i >=0 ; i--) {
            if(i>0){
                dp[i]=dp[i-1]*p[coins]+dp[i]*(1-p[coins]);
            }
            else
                dp[i]*=(1-p[coins]);
        }
    }
    double answer=0;
    for (int heads = 0; heads <=n ; ++heads) {
        ll tails=n-heads;
        if(heads>tails)
            answer+=dp[heads];
    }
    cout<<fixed<<setprecision(10)<<answer<<"\n";
    /*ll a[2];
    a[0]=1;
    a[1]=2*a[0]+a[1]*1;
    cout<<a[0]<<"\n";
    cout<<a[1]<<"\n";*/
    return 0;
}
