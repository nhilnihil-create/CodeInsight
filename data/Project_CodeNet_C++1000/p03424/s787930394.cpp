#include <bits/stdc++.h>
using namespace std;

int main() {
 int N,i,p=0,w=0,y=0,g=0;
  cin >> N;
 
 
  for(i=0;i<N;i++){
    string s;
    cin >> s;
    if(s=="P"){
      p++;
    }else if(s=="W"){
      w++;
    }
    else if(s=="G"){
      g++;
    }
    else if(s=="Y"){
      y++;
    }
  }
  
  if(p && w && g && y){
    cout << "Four" << endl;
}else{
    cout << "Three" << endl;
  }
}
