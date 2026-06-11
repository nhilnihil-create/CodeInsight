#include<iostream>
using namespace std;
double abs(double x){
  return (x<0?-x:x);
}
int main(){
  int N,T;
  cin>>N>>T;
  int c[N],t[N];
  for(int i=0;i<N;i++) cin>>c[i]>>t[i];
  int min=-1;
  for(int i=0;i<N;i++){
    if(t[i]<=T&&min==-1){
      min=c[i];
    }else if(t[i]<=T&&c[i]<min){
      min=c[i];
    }
  }
  cout<<(min==-1?"TLE":to_string(min))<<endl;
  return 0;
}