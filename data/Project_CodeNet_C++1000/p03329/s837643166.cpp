#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end() 
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[100001];
signed main(){
    speed;
    int n; cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] != INT_MAX) {
            for(int j = 1; j <= 5; j++) {
                if(i + j <= n) {
                    dp[i + j] = min(dp[i + j], dp[i] + j);
                }
            }
            for(int j = 1; j < 6; j++) {
                if(i + pow(9, j) <= n) {
                    dp[i + pow(9, j)] = min(dp[i + pow(9, j)], dp[i] + 1);
                }
            }
            for(int j = 1; j < 7; j++) {
                if(i + pow(6, j) <= n) {
                    dp[i + pow(6, j)] = min(dp[i + pow(6, j)], dp[i] + 1);
                } 
            }
        }
    }
    cout << dp[n];
    return 0;
}