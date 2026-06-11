#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(i, a) for (auto &i: (a))
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();
signed main () {
    clock_t beg = clock();
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif 
    int t=1; 
    // cin >> t;    
    int tt = t;
    while (t--) {
        // cout << "Case #" << tt - t << ": "; 
        // solve();
        int n;
        cin>>n;
        int K;
        cin>>K;
        int cost[n];
        rep(i,0,n){
            cin>>cost[i];
        }
        int dp[n+1]={0};
        for( int i=2;i<=n;i++){
            int op1= INT_MAX;
             for(int k=1;k<=K;k++){
                if(i-k>0){
                    op1 = min(op1,dp[i-k]+abs(cost[i-1]-cost[i-1-k]));
                }
            }
            dp[i]= op1;
        }
        // for( int i=1;i<=n;i++){
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
        cout<<dp[n];

    }
    // cerr << "\nExecution time: " << (clock() - beg) / 1000 << '\n';
    return 0;
}
