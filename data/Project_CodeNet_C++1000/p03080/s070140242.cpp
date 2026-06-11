#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N,red=0,blue=0;
  string s;
  cin>>N>>s;
  for(int i=0;i<N;i++){
    if(s.at(i)=='B') blue++;
    else red++;
  }
  if(red>blue) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
