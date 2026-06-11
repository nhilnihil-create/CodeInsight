#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,C,F=1,Q=167167167;
  cin>>N>>A>>B>>C;
  vector<int> l(N);
  for(int i=0;i<N;i++){
    cin>>l[i];
    F*=4;
  }
  for(int i=1;i<F;i++){
    int D=i,X=0,Y=0,Z=0,K=0;
    for(int j=0;j<N;j++){
      if(D%4==1){
        X+=l[j];
      }
      else if(D%4==2){
        Y+=l[j];
      }
      else if(D%4==3){
        Z+=l[j];
      }
      else{
        K++;
      }
      D/=4;
    }
    if(X*Y*Z){
      Q=min(Q,abs(A-X)+abs(B-Y)+abs(C-Z)+10*(N-K-3));
    }
  }
  cout<<Q<<endl;
}