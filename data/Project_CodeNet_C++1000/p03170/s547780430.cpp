#include<bits/stdc++.h>
#pragma GCC optimize ("-O3")
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define int long long
#define double long double
#define pb push_back
int32_t main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0;i < n; i++)
        cin >> a[i];
    bool dp[k+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1;i <= k; i++){
        for(int j = 0; j < n; j++){
            if(a[j]<=i && !dp[i-a[j]]){
                dp[i] = true;
            }
        }
    }
    if(dp[k])
        cout << "First" << "\n";
    else
        cout << "Second " << "\n";
    return 0;
}