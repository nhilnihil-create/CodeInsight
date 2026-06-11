#include <bits/stdc++.h>
using namespace std ;

int main()
{ 
  int a, b, c, d ;
  cin >> a >> b >> c >> d ;
  vector<int> e = {1, 4, 7, 9} ;
  vector<int> f = {a, b, c, d} ;
  sort(f.begin(), f.end()) ;

  if(e == f)
  {
    cout << "YES" << endl ;
  }
  else
  {
    cout << "NO" << endl ;
  }
  
}
