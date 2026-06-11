#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll n;
double dp[301][301][301];
double solve(ll one, ll two, ll three){
    if(one < 0 || two < 0 || three < 0){
        return 0;
    }
    if(one == 0 && two == 0 && three == 0){
        return 0;
    }
    if(dp[one][two][three] > 0){
        return dp[one][two][three];
    }
    ll total = one + two + three;
    double ans = n + one*solve(one-1,two,three) + two*solve(one+1,two-1,three) + three*solve(one,two+1,three-1);
    ans/=total;
    return dp[one][two][three] = ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(dp,-1,sizeof(dp));
    ll one=0, two=0, three=0;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        if(x == 1){
            one++;
        }
        else if(x == 2){
            two++;
        }
        else if(x == 3){
            three++;
        }
    }
    cout<<fixed<<setprecision(10)<<solve(one,two,three)<<"\n";
}
    
    
