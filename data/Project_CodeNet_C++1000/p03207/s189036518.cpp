#include<iostream>
using namespace std;
int main(){
  int N;
  cin>>N;
  int p[N];
  for(int i=0;i<N;i++)cin>>p[i];
  int sum=0,max=0;
  for(int i=0;i<N;i++){
    if(max<p[i])max=p[i];
    sum+=p[i];
  }
  cout<<sum-max/2<<endl;
  return 0;
}