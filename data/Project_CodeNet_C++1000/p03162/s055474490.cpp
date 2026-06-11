#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1LL<<60;
const ll mod = 1e9 + 7;
 
int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}
 
ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

bool is_prime(long long N){
    if (N == 1) return false;
    for (long long i = 2;i * i <= N;i++){
        if (N % i == 0) return false;
    }
    return true;
}
 
ll lcm(ll a,ll b){
    return ((a * b == 0)) ? 0 : (a / gcd(a,b) * b);
}
 
double DegreeToRadian(double degree){
    return degree * M_PI / 180.0;
}
 
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
 
///////////////////////////////////////////////////////////////////////////////////
int dp[100010][3];
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);

    for (int i = 1;i <= n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0;i <= n;i++){
        for (int j = 0;j < 3;j++){
            dp[i][j] = 0;
        }
    }

    for (int i = 1;i <= n;i++){
        for (int j = 0;j < 3;j++){
            if (j == 0){
                dp[i][j] = max(dp[i-1][1] + b[i], dp[i-1][2] + c[i]);
            }
            else if (j == 1){
                dp[i][j] = max(dp[i-1][0] + a[i], dp[i-1][2] + c[i]);
            }
            else {
                dp[i][j] = max(dp[i-1][0] + a[i], dp[i-1][1] + b[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0;i < 3;i++){
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;
}