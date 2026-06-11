#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> T(N+1),X(N+1),Y(N+1);
  for(int i=1;i<N+1;i++){
    cin >> T.at(i) >> X.at(i) >> Y.at(i);
  }
  bool a=false;//だめならtrue
  for(int i=0;i<N;i++){
    int dt=T.at(i+1)-T.at(i);
    int dist=abs(X.at(i+1)-X.at(i))+abs(Y.at(i+1)-Y.at(i));
      if((dist+dt)%2==1){
        a=true;
        break;
      }
      if(dist>dt){
        a=true;
        break;
      }
  }
  if(a){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}