#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#include <queue>
#include <stack> 
#include <sstream>
#include <set>

typedef  long long ll;
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = { 0, 1, 0,-1};
const int INF = 1e9;
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
#define REVERSE(a) reverse(a.begin(),a.end())
int guki (int a){
    if(a%2==0) return 0;
    else return 1;
}
int gcd(int a, int b){
    if(a%b==0){
        return b;
    }else{
        return (gcd(b,a%b));
    }
}
int lcm(int a, int b){
    int x = gcd(a,b);
    return (a*b/x);
}
ll nCr (ll n, ll r){
    ll ans = 1;
    for(ll i = n ; i > n-r ; i --){
        ans *= i;
    }
    for(ll i = 1 ; i<= r; i ++){
        ans /= i;
    }
    return ans ;
}

int nPr (int n,int r){
    int ans = 1;
    for(int i = n ; i > n-r ; i --){
        ans *= i;
    }
    return ans ;
}




using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    REP(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<int>> dp(n,vector<int>(3));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    FOR(i,1,n){
        dp[i][0] = max(dp[i-1][1]+a[i], dp[i-1][2] + a[i]);
        dp[i][1] = max(dp[i-1][0]+b[i], dp[i-1][2] + b[i]);
        dp[i][2] = max(dp[i-1][1]+c[i], dp[i-1][0] + c[i]);
    }
    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) <<endl;

   

}



