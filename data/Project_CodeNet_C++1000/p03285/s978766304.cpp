#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  for(int i=0;i<26;i++){
    for(int j=0;j<16;j++){
      if(i*4+j*7==N){cout<<"Yes"<<endl; return 0;}
    }
  }
  cout<<"No"<<endl;
}