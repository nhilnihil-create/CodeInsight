#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  if(N==0){
    cout<<0<<endl;
    return 0;
  }
  vector<int>D;
  while(N != 0){
      int m = N%(-2);
      //余りが-1のとき1を出力する
      if(m<0) m+=2;
      D.emplace_back(m);
      N = (N-m)/(-2);
  }
  
  for(int i=0;i<D.size();i++){
    cout<<D[D.size()-1-i];
  }
  cout<<endl;
  
  return 0;
}

  
      
          