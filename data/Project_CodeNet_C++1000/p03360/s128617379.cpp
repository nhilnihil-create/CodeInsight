#include<iostream>
using namespace std;
int main(){
  int a[3],k,sum=0,max=0;
  cin>>a[0]>>a[1]>>a[2];
  cin>>k;
  for(int i=0;i<3;i++){
    sum+=a[i];
    if(max<a[i]) max=a[i];
  }
  sum=sum-max;
  for(int i=0;i<k;i++){
    max*=2;
  }
  cout<<sum+max<<endl;
  return 0;
}