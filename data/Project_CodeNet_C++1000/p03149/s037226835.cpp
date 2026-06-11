#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t,u,v;
  cin >> s >> t >> u >> v;
  
  string w = s+t+u+v;
  
  int n=0;
  int o=0;
  int p=0;
  int q=0;
  
  for(int i=0;i<4;i++){
    if(w.at(i)=='1'){
      n++;
    }
    
    else if(w.at(i)=='9'){
      o++;
    }
    
    else if(w.at(i)=='7'){
      p++;
    }
    
    else if(w.at(i)=='4'){
      q++;
    }
  }
  
  if(n==1&&o==1&&p==1&&q==1){
    cout << "YES" << endl;
  }
  
  else{
    cout << "NO" << endl;
  }
}