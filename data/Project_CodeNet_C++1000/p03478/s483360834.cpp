#include <bits/stdc++.h>
using namespace std;

int k(int v){
  int sum=0;
while(v){sum+=v%10;v/=10;}
  return sum;
}

int main(){
int n,a,b,c=0;
  cin>>n>>a>>b;
  for(int i=1;i<=n;i++){
  if(k(i)>=a&&k(i)<=b){c+=i;}
  }
  cout<<c;
  return 0;
}