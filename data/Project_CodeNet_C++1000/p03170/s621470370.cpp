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
    int a,maxi;
    cin>>a>>maxi;

    int b[a];
    rep(i,0, a){
        cin>>b[i];
    }
    vector<bool> dp(maxi+1);
    dp[0]=false;
    //dp[i] is true if first player using those stones wins
    for(int i=1;i<=maxi;i++){
        for(int x:b){
            if(i>=x&&(!dp[i-x])){
                dp[i]= true;
            }

        }
    }
    if(dp[maxi]){
        cout<<"First"<<endl;
    } 
    else{
        cout<<"Second";
    }
    return 0;
}
