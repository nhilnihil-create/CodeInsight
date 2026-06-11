#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  for(int i=0;i<=9;i++){
    if(N<=i*100+i*10+i){
      cout<<i*100+i*10+i<<endl;
      break;
    }
  }
}