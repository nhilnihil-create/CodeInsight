#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 2100000000
#define MOD 1000000007

int main(){
  int N;
  cin>>N;
  vector<vector<char>> S(N,vector<char>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>S[i][j];
    }
  }

  int ans=0;
  for(int k=0;k<N;k++){
    bool flag=true;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(S[(k+i)%N][j]!=S[(k+j)%N][i]){
          flag=false;
          break;
        }
      }
      if(!flag){
        break;
      }
    }
    if(flag){
      ans+=N;
    }
  }
  cout<<ans<<endl;
}
