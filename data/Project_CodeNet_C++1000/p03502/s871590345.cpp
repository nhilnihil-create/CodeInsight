#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string N;
  cin>>N;
  
  int x=stoi(N);
  
  int y=0;
  
  
  for(int i=0;i<N.size();i++){
    y+=N[i]-'0';
  }
  
  if(x%y==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}