#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,int>>>;
#define INF 1000000000000000000
#define MOD 1000000007

int main(){
  int N;
  string S;
  cin>>N>>S;

  vector<vector<ll>> dp(N,vector<ll>(N,0));
  for(int j=0;j<N;j++){
    dp.at(0).at(j)=1;
  }

  for(int i=1;i<N;i++){
    if(S.at(i-1)=='<'){
      for(int j=0;j<N-i;j++){
        dp.at(i).at(j)+=dp.at(i-1).at(j+1);
        dp.at(i).at(j)%=MOD;
      }
      for(int j=N-2;j>=0;j--){
        dp.at(i).at(j)+=dp.at(i).at(j+1);
        dp.at(i).at(j)%=MOD;
      }
    }else{
      for(int j=0;j<N-i;j++){
        dp.at(i).at(j)+=dp.at(i-1).at(j);
        dp.at(i).at(j)%=MOD;
      }
      for(int j=1;j<N;j++){
        dp.at(i).at(j)+=dp.at(i).at(j-1);
        dp.at(i).at(j)%=MOD;
      }
    }
  }

  cout<<dp.at(N-1).at(0)<<endl;
}
