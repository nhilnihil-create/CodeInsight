#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X,Y;
  cin>>N>>M>>X>>Y;
  vector<int> x(N);
  vector<int> y(M);
  for (int i=0; i<N; i++){
    cin>>x.at(i);
  }
  for (int i=0; i<M; i++){
    cin>>y.at(i);
  }
  bool flag2=false;
  for (int Z=-100; Z<=100; Z++){
    bool flag=false;
    for (int i=0; i<N; i++){
      if (Z<=x.at(i)){
        flag=true;
      }
    }
    for (int i=0; i<M; i++){
      if (Z>y.at(i)){
        flag=true;
      }
    }
    if (Z<=X||Y<Z){
      flag=true;
    }
    if(!flag){
      flag2=true;
      break;
    }else{
      continue;
    }
  }
  if (flag2){
    cout<<"No War"<<endl;
  }else{
    cout<<"War"<<endl;
  }
}
      