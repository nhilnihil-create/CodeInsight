#include <bits/stdc++.h>
using namespace std;

int main() {
 vector<char> f(3) ;
 vector<char> s(3) ;
  
  for(int i = 0 ; i < 3 ; i++){
    cin >> f[i] ;
  }
  for(int i = 0 ; i < 3 ; i++){
    cin >> s[i] ;
  }
  reverse(s.begin(),s.end()) ;
  
  if(f==s) cout << "YES" << endl;
  else cout << "NO" << endl;
}

