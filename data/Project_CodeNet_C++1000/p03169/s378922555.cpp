#include<bits/stdc++.h>
#define ll  long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
#define pii pair<ll,ll>
#define ve vector
#define piii pair<pii, ll>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

ll power(ll x, ll n, ll m)
{
    if(n==0)
        return 1;
    if(n==1)
        return x;
    x%=m;
    if(n%2)
        return (x*(power((x*x)%m, n/2, m)%m))%m;
    return power((x*x)%m, n/2, m)%m;
}

 
double dp[301][301][301];
double solve(int one, int two, int three, int& n)
{
    if(one < 0 || two < 0 || three < 0)
        return 0;
    if(three == 0 && two == 0 && one == 0)
        return 0;
 
    if(dp[one][two][three] > 0)
        return dp[one][two][three];
 
    double remaining = one + two + three;
    double exp_val = n+ one*solve(one-1,two,three,n) + two*solve(one+1,two-1,three,n) +
                    three*solve(one,two+1,three-1,n);
 
    return dp[one][two][three] = exp_val/remaining;
}
 
int main(){
    
    int n,one=0,two=0,three=0;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 1)one++;
        else if(x == 2)two++;
        else three++;
    }

    for(int i=0; i<301; i++){
        for(int j=0; j<301; j++){
            for(int k=0; k<301; k++)
                dp[i][j][k] = -1;
        }
    }
    cout<<fixed<<setprecision(9)<<solve(one,two,three,n);

    return 0;
}