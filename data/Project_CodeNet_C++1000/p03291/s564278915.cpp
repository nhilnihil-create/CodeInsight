#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;
using ll=long long;
using P=pair<int,int>;
long long modpow(long long a, long long n, long long mod=1e9+7) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
int main(){
    const int MOD=1e9+7;
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(4,0)));
    if(s[0]=='A')dp[0][0][0]=1;
    else if(s[0]=='?')dp[0][0][1]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                dp[i][j][k]=dp[i-1][j][k];                
            }
        }
        if(s[i]=='A')dp[i][0][0]++;
        else if(s[i]=='B'){
            dp[i][1][0]+=dp[i-1][0][0];
            dp[i][1][1]+=dp[i-1][0][1];
        }else if(s[i]=='C'){
            dp[i][2][0]+=dp[i-1][1][0];
            dp[i][2][1]+=dp[i-1][1][1];
            dp[i][2][2]+=dp[i-1][1][2];
        }else{
            dp[i][0][1]++;
            for(int j=1;j<3;j++){
                for(int k=1;k<=j+1;k++){
                    dp[i][j][k]+=dp[i-1][j-1][k-1];
                }
            }
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                dp[i][j][k]%=MOD;
            }
        }
    }
    int q=0;
    for(int i=0;i<n;i++){
        if(s[i]=='?')q++;
    }
    int ret=0;
    for(int i=0;i<=3;i++){
        ret+=(ll)dp[n-1][2][i]*modpow(3,q-i)%MOD;
        ret%=MOD;
    }
    cout<<ret<<endl;
}

