#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(i, a) for (auto &i: (a))
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
int dp[100005][4];
// int maxsummerpoints(int days, int a[],int b[],int c[]){
//     if(days ==0||user==0){
//         return 0;
//     }
//     if( dp[days][user]!=0){
//         return dp[days][user];
//     }
//     int op1 = a[days-1]+maxsummerpoints(days-1,a,b,c);
//     int op2 = b[days-1]+maxsummerpoints(days-1,a,b,c);
//     int op3 = c[days-1]+maxsummerpoints(days-1,a,b,c);
//     int best= max(op1,max(op2,op3));
//     return dp[days]=best;
    
// }
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

        int n;
        cin>>n;
        int a[n],b[n],c[n];

        rep(i,0,n){
            cin>>a[i]>>b[i]>>c[i];
        }
        memset(dp,0,sizeof(dp));
        // for( int i=1;i<=n;i++){
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
        dp[1][1]=a[0];
        dp[1][2]=b[0];
        dp[1][3]=c[0];
        for(int i=2;i<=n;i++){
            dp[i][1]= a[i-1]+max(dp[i-1][2],dp[i-1][3]);
            dp[i][2]= b[i-1]+max(dp[i-1][1],dp[i-1][3]);
            dp[i][3]= c[i-1]+max(dp[i-1][1],dp[i-1][2]);
        }
        int ans=INT_MIN;
        for(int i=1;i<=3;i++){
            ans = max( ans,dp[n][i]);
        }
        cout<<ans<<endl;
        // cout<<maxsummerpoints(n,a,b,c)<<endl;

    }
    // cerr << "\nExecution time: " << (clock() - beg) / 1000 << '\n';
    return 0;
}
