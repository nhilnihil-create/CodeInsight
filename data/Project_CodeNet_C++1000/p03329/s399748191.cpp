#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int n;
    cin >> n;
    vector<int>dp(n+10000,n);
    dp[0] = 0;
    for(int i = 0;i<n;i++) {
        for(int pow6 = 1;i+pow6<=n;pow6 *= 6) {
            chmin(dp[i+pow6],dp[i]+1); 
        }
        for(int pow9 = 1;i+pow9<=n;pow9 *= 9) {
            chmin(dp[i+pow9],dp[i]+1); 
        }
    }
    cout << dp[n] << endl;
}    