#include <bits/stdc++.h>
using namespace std;
int main (){
  int N,sum,s,t;
  cin>>N;
  sum=0;
  s=0;
  t=N;
  for(int i=0;t>0;i++){
    s=t%10;
    sum+=s;
    t/=10;
  }
  if(N%sum==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}