#include<iostream>
using namespace std;

int add(int n){
  int i =0;
  int keta[4];
  int ans=0;
  while(n>0){
    keta[i]=n%10;
    n/=10;
    ans+=keta[i];
    i++;
  }
  return ans;
}

int main(){
  int n,a,b;
  cin>>n;
  cin>>a;
  cin>>b;
  int sum=0;
  for(int i=0;i<=n;i++){
    int x=add(i);
    
    if(x>=a && x<=b){
      sum+=i;
    }
  }
  cout<<sum<<endl;
  return 0;
}
    
         
  
  