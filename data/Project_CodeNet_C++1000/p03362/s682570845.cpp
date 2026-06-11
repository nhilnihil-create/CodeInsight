#include <bits/stdc++.h>
using namespace std;

int main(){
  int B = 55556;
  vector<int> V(B,1);
  vector<int> P;
  //vector<int> R(5,0);
  V[0] = 0;
  for(int i=2;i<B;i++){
    if(V[i]==1){
      for(int k=2;k*i<B;k++){
        V[k*i]=0;
      }
      P.push_back(i);
      //R[i%5] ++;
    }
  }
  int N;cin >> N;
  int count = 0;
  for(int i=0;i<P.size();i++){
    if(P[i]%5==1){
      cout << P[i];
      count ++;
      if(count < N){
        cout << " ";
      }else{
        cout << endl;
        return 0;
      }
    }
  }
  //for(int r=0;r<5;r++){
  //  cout << r << " " << R[r] << endl;
  //}
}