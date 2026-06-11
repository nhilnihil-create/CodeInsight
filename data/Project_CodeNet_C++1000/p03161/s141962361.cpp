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
    int n,k;
    cin >> n >> k;
    vector<int> vec(n),dp(n);

    REP(i,n){
        cin >> vec[i];
    }

    dp[0] = 0;dp[1] = abs(vec[0] - vec[1]);

    for(int i = 2; i< n;i++){
        dp[i] = dp[i-1] + abs(vec[i] - vec[i-1]);
        for(int j = 2;j <= k;j++){
            if(i-j>=0) dp[i] = min(dp[i], (dp[i-j] + abs(vec[i] - vec[i-j])));
        }
    }
    cout << dp[n-1]<<endl;
}



