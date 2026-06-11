#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  int s1=0,s2=0,ans,s;
  vector<vector<int>> vec(2,vector<int>(N));
  for(int i=0;i<2;i++){
    for(int j=0;j<N;j++){
      cin >> vec[i][j];
      if(i==0){
        s1+=vec[i][j];
      }
      else{
        s2+=vec[i][j];
      }
    }
  }
  ans=0;
  for(int i=0;i<N;i++){
    if(i==0){
      s=vec[0][i]+s2;
    }
    else{
      s=s+vec[0][i]-vec[1][i-1];
    }
    ans=max(ans,s);
  }
  cout << ans <<endl;
}
