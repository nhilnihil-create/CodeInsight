#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(i, a) for (auto &i: (a))
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
 

 
signed main () {
    clock_t beg = clock();
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif 
    int a;
    cin>>a;
    // int mod = 1000000000 +7;
    // at any state we have no ofheads
    vector<double> dp(a+1);
    dp[0]=1;//probability of o heads is 1;
    for(int i=0;i<a;i++){
        double phead;
        cin>>phead;
        for(int coin= i+1;coin>=0;coin--){
            dp[coin]= (coin==0? 0 :dp[coin-1]*(phead))+ dp[coin]*(1-phead);
        }
    }
    int number = a/2;
    double ans=0;
    for(int heads=0;heads<=a;heads++ ){
        int tails= a-heads;
        if( heads>tails){
            ans+=dp[heads];
        }
    }
    cout<<ans<<endl;
    return 0;
}
