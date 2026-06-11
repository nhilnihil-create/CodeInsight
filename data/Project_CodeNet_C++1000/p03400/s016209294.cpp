#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,D,X;
  cin>>N>>D>>X;
 
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  for(int i=0;i<N;i++){
    int Y=1;

    while(Y<=D){
      X+=1;
      Y+=A.at(i);
    }
  }
  cout<<X;
}
      

  
