#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<map>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 110000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

ll dp[110000][4];

int main(){
    string s;
    cin>>s;
    dp[0][0]=1;
    for(int i=0;i<(int)s.size();i++){
        for(int j=0;j<4;j++){
            if(j==3){
                if(s[i]=='?') dp[i+1][j]+=dp[i][j]*3;
                else dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=MOD;
                continue;
            }
            if(j==0 && s[i]=='A') dp[i+1][1]+=dp[i][j];
            else if(j==1 && s[i]=='B') dp[i+1][2]+=dp[i][j];
            else if(j==2 && s[i]=='C') dp[i+1][3]+=dp[i][j];
            
            if(s[i]=='?'){
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][j]+=dp[i][j]*3;
            } else{
                dp[i+1][j]+=dp[i][j];
            }
            dp[i+1][j+1]%=MOD;
            dp[i+1][j]%=MOD;
        }
    }
    cout<<dp[(int)s.size()][3]<<endl;
}

