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

int rec(int n){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int res = n;
    for(int pow6 = 1; pow6 <= n; pow6*=6) res = min(res, rec(n-pow6) + 1);
    for(int pow9 = 1; pow9 <= n; pow9*=9) res = min(res, rec(n-pow9) + 1);
    return dp[n] = res;
}

int main(){
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(n) << endl;
}