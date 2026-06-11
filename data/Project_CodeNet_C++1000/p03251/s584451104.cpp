#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M,X,Y;
  cin>>N>>M>>X>>Y;
  int a=-100;
  int b=100;
  for(int i=0;i<N;i++){
    int x;
  cin>>x;
    a=max(a,x);
  }
  for(int j=0;j<M;j++){
    int y;
  cin>>y;
    b=min(b,y);
  }
  if(a<b&&X<=a&&Y>=b){
  cout<<"No War"<<endl;
  }
  else{
  cout<<"War"<<endl;
  }
  
}
