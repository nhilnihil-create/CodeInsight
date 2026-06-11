#include<iostream>
#include<vector>
using namespace std;
int main(){
int n,a,sum=0,max=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    sum+=a;
    if(a>max) max=a;
  }
  sum-=max/2;
  cout<<sum<<endl;
  return 0;
}