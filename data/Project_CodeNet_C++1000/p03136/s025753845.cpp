#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int big=0;
  int sum=0;
  for(int i=0;i<N;i++){
   int a;
    cin>>a;
    sum+=a;
   	big=max(big,a);
    }
  
  if(big< sum-big ){
  cout<<"Yes"<<endl;
  }
  else{
  cout<<"No";
  }
}