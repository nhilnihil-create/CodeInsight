#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int sum1=0;
  sort(a,a+n,greater<int>());
  for(int i=0;i<n;i+=2){
    sum1+=a[i];
  }
  int sum2=0;
  for(int i=1;i<n;i+=2){
    sum2+=a[i];
  }
  cout<<sum1-sum2<<endl;
  return 0;
}