#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X,Y;cin>>N>>M>>X>>Y;
  vector<int> x(N),y(M);
  for(int i=0;i<N;i++) cin>>x.at(i);
  for(int i=0;i<M;i++) cin>>y.at(i);
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  int maxx=x.at(N-1);
  int miny=y.at(0);
  bool conflict=true;
  for(int i=X+1;i<=Y;i++){
    if(maxx<i && i<=miny) conflict=false;
  }
  cout<<(conflict?"War":"No War")<<endl;
  
}
  
