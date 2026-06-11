#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  string s;
  cin >> n >> s;
  
  string t,u;
  int count,saidai = 0;
  

  for ( int i = 1; i < n; i++){
    t = s.substr(0,i);
    u = s.substr(i,n-i);
    count = 0;
    
    sort(t.begin(),t.end());
    sort(u.begin(),u.end());
    
    t.erase(unique(t.begin(),t.end()),t.end());
    u.erase(unique(u.begin(),u.end()),u.end());
    
    
    for ( int j = 0; j < t.size(); j++){
      for ( int k = 0; k < u.size(); k++){
        if ( t[j] == u[k] ){
          count++;
        }
      }
    }
    saidai = max(saidai,count);
  }
   
  cout << saidai << endl;
  
}