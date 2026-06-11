#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
#define co(n) cout << n << endl
using namespace std;
int main(){
  string s;
  cin >> s;
  
  int c=0;
  rep(i,0,4) if(s.at(i)=='2') c++;
  co(c);
  
  
  return 0;
}
