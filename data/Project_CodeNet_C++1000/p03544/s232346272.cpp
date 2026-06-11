#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  uint64_t prepre=2;
  uint64_t pre=1;
  uint64_t answer=3;
  if(N==0){
    cout<<prepre<<endl;
    return 0;
  }else if(N==1){
    cout<<pre<<endl;
    return 0;
  }
  for(int i=1;i<N;i++){
    answer=prepre+pre;
    prepre=pre;
    pre=answer;
  }
  cout<<answer<<endl;
  return 0;
}
