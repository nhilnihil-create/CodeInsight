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
const int INF = 1e9 + 5;
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
    string s,t;
    cin >> s >> t;
    
    int n = s.size(),m = t.size();

    vector<vector<int>> dp(3100,vector<int> (3100));

    for(int i = 0;i<=n;i++){
        for(int j=0; j<=m;j++){
            if(i == 0 || j == 0){
                dp[0][0] = 0;
                continue;
            }

            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1] == t[j-1]){
                dp[i][j] = max(dp[i-1][j-1]+1 , dp[i][j]);
            }
             
        }
       
    }

    string ans = "";
    while (n > 0 && m >0){
        if(dp[n][m] == dp[n-1][m]) n--;
        else if(dp[n][m] == dp[n][m-1]) m--;
        else {
            ans += s[n-1];
            n--; m--;
        } 
    }
    REVERSE(ans);
    cout<< ans <<endl;
}



