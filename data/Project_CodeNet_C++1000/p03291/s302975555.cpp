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

const ll mod = 1e9+7;
ll dp[100010][4] = {};

int main(){
    string s;
    cin >> s;
    int len = s.length();


    dp[len][3] = 1;
    rep(i,3) dp[len][i] = 0;

    for(int i = len-1; i >= 0; i--){

        int t1=0,t2=0;
        for(int j = 3; j >= 0; j--){
            dp[i][j] = dp[i+1][j];
            if(s[i] == '?')dp[i][j] = (3 * dp[i+1][j]);

            if(j < 3){
                if(s[i] == '?'){
                    t1 = 3; t2 = 1;
                }else{ 
                    t1 = 1;
                    if(s[i] == "ABC"[j]) t2 = 1;
                    else t2 = 0;
                }
                
                dp[i][j] = t1*dp[i+1][j] + t2*dp[i+1][j+1];
            }

            dp[i][j] = dp[i][j] % mod;
        }
    }

    // rep(j,4){        
    //     rep(i,len+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    cout << dp[0][0] << endl;
    return 0;
}