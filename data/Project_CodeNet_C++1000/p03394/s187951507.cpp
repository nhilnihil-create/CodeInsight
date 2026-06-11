#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  long long n,sum=0;
  cin>>n;
  long long a[n+4]={},k=0;
  if(n==3){
    cout<<"2 5 63"<<endl;
    return 0;
  }else if(n==4){
    cout<<"2 5 20 63"<<endl;
    return 0;
  }else if(n==5){
    cout<<"2 5 20 30 63"<<endl;
    return 0;
  }
  for(long long i=0;i<=n;i+=4){
    a[i]=6*k;
    a[i+1]=6*k+2;
    a[i+2]=6*k+3;
    a[i+3]=6*k+4;
    k++;
    sum+=a[i]+a[i+1]+a[i+2]+a[i+3];
  }
  sum-=a[n+1]+a[n+2]+a[n+3];
  if(sum%6==2){
    a[5]=a[n-n%4]+6;
  }else if(sum%6==3){
    a[6]=a[n-n%4]+6;
  }else if(sum%6==5){
    a[6]=a[n-n%4]+4;
  }
  for(long long j=1;j<n;j++) cout<<a[j]<<" ";
  cout<<a[n]<<endl;
  return 0;
}
