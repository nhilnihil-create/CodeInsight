#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  cin>>n;
  vector<int> x(n),y(n);
  for(int i=0;i<n;i++){
    cin>>x[i];
    y[i]=x[i];
  }
  sort(y.begin(),y.end());
  int med1=y[n/2-1];
  int med2=y[n/2];
  for(int i=0;i<n;i++){
    if(x[i]<=med1){
      cout<<med2<<endl;
    }else{
      cout<<med1<<endl;
    }
  }
  return 0;
}