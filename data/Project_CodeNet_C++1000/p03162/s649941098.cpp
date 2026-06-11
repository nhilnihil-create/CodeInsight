#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int dp[100001][3];

int main(){
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    fast_io();
    
    int n;
    cin>>n;

    vector<vector<int > > a(n+1, vector<int>(3, 0));

    for(int i=0; i<n; i++){
        int x, y, z;
        cin>>x>>y>>z;

        a[i][0] = x;
        a[i][1] = y;
        a[i][2] = z;
    }

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for(int i=1; i<n; i++){
        dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = a[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }    

    cout<<max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2])<<"\n";

    return 0;

}
  