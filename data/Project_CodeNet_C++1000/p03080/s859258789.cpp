#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  int n ;
  cin >> n ;
  
  string s ;
  cin >> s ;
  
  int c =0;
  for(int i=0; i<s.size() ; i++ ){
    if( s.at(i)=='R'){
      c++;
    }
  }
  
  if(c>n/2){
    cout << "Yes" << endl;
  }
  
  else {
    cout << "No" << endl;
  }
}