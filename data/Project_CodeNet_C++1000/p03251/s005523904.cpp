#include<iostream>
using namespace std;
int main(){
  int N,M,X,Y;
  cin>>N>>M>>X>>Y;
  int x[N],y[M];
  for(int i=0;i<N;i++) cin>>x[i];
  for(int i=0;i<M;i++) cin>>y[i];
  int max_x=-100, min_y=100;
  for(int i=0;i<N;i++) if(max_x<x[i]) max_x=x[i];
  for(int i=0;i<M;i++) if(min_y>y[i]) min_y=y[i];
  int r1=min_y-X,r2=Y-max_x,r3=min_y-max_x,r4=Y-X;
  cout<<(r1>0&&r2>0&&r3>0&&r4>0?"No War":"War")<<endl;
}