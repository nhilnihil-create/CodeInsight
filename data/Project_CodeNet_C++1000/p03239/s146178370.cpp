#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
int main(){
  int N; int T; cin>>N>>T;
  vector<vector<int>> S(N,vector<int>(2));
  int A=0; //TLEしないルート数
  int B=1001; //コスト
  for(int i=0; i<N; i++){
    for(int j=0; j<2; j++){
      cin>>S.at(i).at(j);
     
    }
    if(S.at(i).at(1)<=T){
      A++;
     B=min(B,S.at(i).at(0));
    }
  }
  if(A!=0)
    cout<<B<<endl;
  else cout<<"TLE"<<endl;
}
  
