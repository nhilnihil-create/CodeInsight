#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int MAX = 110000;
int dp[MAX];

int main(){
    int n; cin >> n;
    for(int i = 0; i < MAX; ++i) dp[i] = n;
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int pow6 = 1; pow6 + i <= n; pow6 *= 6) dp[pow6 + i] = min(dp[pow6 + i], dp[i] + 1);
        for(int pow9 = 1; pow9 + i <= n; pow9 *= 9) dp[pow9 + i] = min(dp[pow9 + i], dp[i] + 1);
    }
    cout << dp[n] << endl;
}