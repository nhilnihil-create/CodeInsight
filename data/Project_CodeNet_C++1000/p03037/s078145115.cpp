#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll dp[e];

//beginner 1999 127

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int l, r;
        cin >> l >> r;
        dp[l] ++;
        dp[r+1] --;
    }
    for(int i=1; i<=n; i++){
        dp[i] += dp[i-1];
    }
    int dem =0;
    for(int i=1; i<=n; i++){
        if(dp[i] >= m){
            dem ++;
        }
    }
    cout << dem;
}
