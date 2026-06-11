#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  LL N,flag=0;
  string S;
  cin>>N;
  for(int i=0; i<N; i++){
    cin>>S;
    if(S=="Y"){
      flag=1;
    }
  }
  if(flag==1){
    cout<<"Four"<<endl;
  }
  else{
    cout<<"Three"<<endl;
  }
}
