#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int r=0;
  int b=0;
  string S;
  cin>>N;
  cin>>S;
  for(int i=0;i<N;i++){
    if(S.at(i)=='R')r++;
    if(S.at(i)=='B')b++;
  }
  if(r>b){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}
