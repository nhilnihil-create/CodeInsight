#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<cmath>
using namespace std;
#define INF 110000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,int> P;


ll dp[110000][4];

int main(){
  int counth;
  string S;
  cin>>S;
  dp[0][0]=1;
  //cout<<S<<endl;
  for(int i=0;i<(int)S.size();i++){
    //cout<<i<<endl;
    for(int j=0;j<4;j++){
      //cout<<j<<endl;
      if(S[i]=='?'){
        //cout<<"?"<<endl;
        if(j<3) dp[i+1][j+1]+=dp[i][j];
        dp[i+1][j]+=dp[i][j]*3;
        //cout<<i+1<<" "<<j+1<<" "<<dp[i+1][j+1]<<endl;
        //cout<<i+1<<" "<<j<<" "<<dp[i+1][j]<<endl;
      }else if(j==S[i]-'A'){
        //cout<<"A"<<endl;
        dp[i+1][j+1]+=dp[i][j];
        dp[i+1][j]+=dp[i][j];
      }else{
        dp[i+1][j]+=dp[i][j];
        //cout<<"X"<<endl;
        //cout<<i+1<<" "<<j<<" "<<dp[i+1][j]<<endl;
      }
      dp[i+1][j+1]%=MOD;
      dp[i+1][j]%=MOD;
      //cout<<i<<" "<<j<<endl;
    }
  }
  cout<<dp[(int)S.size()][3]<<endl;
}
