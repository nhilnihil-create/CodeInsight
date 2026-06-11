#include<bits/stdc++.h>
using namespace std;
int main(){
  long n;
  cin>>n;
  int min;
  for(int i=1;i<=n/2;i++){
    int sum=0;
    int x=i;
    int y=n-i;
    for(int j=0;j<5;j++){
      sum+=x%10;
      sum+=y%10;
      x=x/10;
      y=y/10;
    }
    if(i==1){
      min=sum;
    }
    else if(sum<min){
      min=sum;
    }
  }
  cout<<min<<endl;
    
}