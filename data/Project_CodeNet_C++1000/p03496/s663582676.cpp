#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  int max=0;
  int maxindex=0;
  
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(abs(a)>=abs(max)){
      max=a;
      maxindex=i;
    }
  }
  
  maxindex++;
  
  int m=2*n-1;
  cout<<m<<endl;
  
  if(max>=0){
    for(int i=1;i<=n;i++){
      cout<<maxindex<<" "<<i<<endl;
    }
    for(int i=1;i<n;i++){
      cout<<i<<" "<<i+1<<endl;
    }
  }else if(max<0){
    for(int i=1;i<=n;i++){
      cout<<maxindex<<" "<<i<<endl;
    }
    for(int i=n;i>1;i--){
      cout<<i<<" "<<i-1<<endl;
    }
  }
  


    return 0;
}