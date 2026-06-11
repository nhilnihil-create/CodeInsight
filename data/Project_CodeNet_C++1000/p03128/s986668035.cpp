#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<string>
#include<stdio.h>
#include<cmath>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define lint long long

int main(){
    int num[10] = {0,2,5,5,4,5,6,3,7,6};
    
    int n, m; cin >> n >> m;
    vector<int> a;
    rep(i, m) { int x; cin >> x; a.push_back(x); }
    sort(all(a), greater<int>());

    int dp[10005];
    dp[0] = 0;
    repn(i, n){
        dp[i] = -1;
        rep(j, m){
            if(i - num[a[j]] >= 0 && dp[i - num[a[j]]] >= 0){
                dp[i] = max(dp[i], dp[i - num[a[j]]] + 1);
            }
        }
    }

    string ans = "";
    int d = dp[n];
    rep(i, d){
        rep(j, m){
            if(n - num[a[j]] >= 0 && dp[n - num[a[j]]] == dp[n] - 1){
                ans = ans + to_string(a[j]);
                n -= num[a[j]];
                break;
            }
        }
    }
    cout<<ans<<endl;
}
