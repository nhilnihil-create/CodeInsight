#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;
  cin>>a>>b;
  int cnt=0;
  if(b<a)cnt--;
  for(int i=1;i<=a;i++){
    for(int j=1;j<=a;j++){
      if(i==j)cnt++;
    }
  }
  cout<<cnt<<endl;
}