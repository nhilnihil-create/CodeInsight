#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() { 
  string s;
  cin>>s;
  int n;
  cin>>n;
  ////
  int iti=0;
 
  rep(i,s.size()){
    if(s[i]=='1'){
     iti++; 
    }
    else{
     break;
    }
  }
  /////////
  if(n<=iti){
    cout<<1<<endl;
  }
  else cout<<s[iti]<<endl;
  
  
  
  
    
  
}