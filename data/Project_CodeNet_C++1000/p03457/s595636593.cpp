#include<iostream>

using namespace std;

int main(){
  int N;
  cin>>N;
  bool f=false;
  int y=0,x=0,t=0;
  for(int i=0;i<N;i++){
    int ti,xi,yi;
    cin>>ti>>xi>>yi;
    auto d=abs(y-yi)+abs(x-xi);
    auto td=ti-t;
    f|=td<d||d-td&1;
    t=ti;
    y=yi;
    x=xi;
  }
  cout<<(f?"No":"Yes")<<endl;
}

