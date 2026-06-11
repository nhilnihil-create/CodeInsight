#include <bits/stdc++.h>
using namespace std ;

int main()
{ 
  int n ;
  string s ;
  cin >> n >> s ;
  int r = count(s.begin(), s.end(), 'R') ;
  int b = count(s.begin(), s.end(), 'B') ;

  if(r > b)
  {
    cout << "Yes" << endl ;
  }
  else
  {
    cout << "No" << endl ;
  }
  
}
