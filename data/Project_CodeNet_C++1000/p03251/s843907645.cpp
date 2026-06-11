#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X,Y;
  cin >> N >> M >> X >> Y;
  vector<int> A(N),B(M);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<M;i++){
    cin >> B.at(i);
  }
  sort(A.rbegin(),A.rend());
  sort(B.begin(),B.end());
  bool a=false;
  if(A.at(0)+1<=B.at(0)){
    for(int i=A.at(0)+1;i<B.at(0)+1;i++){
      if(X<i && i<=Y){
        a=true;
        break;
      }
    }
  }
  if(a){
    cout << "No War" << endl;
  }
  else{
    cout << "War" << endl;
  }
}
        
      
   
  