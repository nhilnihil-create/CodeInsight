#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<vector<int>> p(N,vector<int>(3));
  for(int i=0;i<N;i++){
    cin>>p.at(i).at(1)>>p.at(i).at(2)>>p.at(i).at(0);
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  int A=0;
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      A=0;
      int H=p.at(0).at(0)+abs(i-p.at(0).at(1))+abs(j-p.at(0).at(2));
      for(int k=1;k<N;k++){
        if(p.at(k).at(0)!=max(0,H-abs(i-p.at(k).at(1))-abs(j-p.at(k).at(2)))){
          A=1;
          break;
        }
      }
      if(A==0){
        A=2;
        cout<<i<<" "<<j<<" "<<H<<endl;
        break;
      }
    }
    if(A==2){
      break;
    }
  }
    
}