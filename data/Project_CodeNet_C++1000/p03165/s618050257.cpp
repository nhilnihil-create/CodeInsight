#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;


int dp[3010][3010];
int main(){
    string s,t;
    cin >> s >> t;
    rep(i,3010){
        rep(j,3010){
            dp[i][j] = 0;
        }
    }

    int n,m;
    n = s.length();
    m = t.length();

    rep(i,n){
        rep(j,m){
            if(s[i] == t[j]){
                dp[i+1][j+1] = max(dp[i][j] + 1, dp[i][j+1]);
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]); 
            }else{
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }

    
    int len = dp[n][m];
    string ans = "";
    int i = n-1;
    int j = m-1;
    while(len > 0){
        if(s[i] == t[j]){
            ans += s[i];
            i--;
            j--;
            len--;
        }else if(dp[i+1][j+1] == dp[i][j+1]){
            i--;
        }else{
            j--;
        }
    }
    
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}