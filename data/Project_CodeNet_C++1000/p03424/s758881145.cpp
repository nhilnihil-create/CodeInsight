#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int ct=0;
  string s;
  
  for(int i=0;i<N;i++){
    
    cin >> s;
    if(s=="Y"){
      ct++;
      break;
    }   
  }
  
  if(ct==1) cout << "Four"<<endl;
  else cout << "Three" << endl;
  
}