#include <bits/stdc++.h>
using namespace std ;

int main()
{ 
  string s ;
  cin >> s ;
  int answer = count(s.begin(), s.end(), 'o') ;
  
  if(15 - s.size() + answer >= 8)
  {
    cout << "YES" << endl ;
  }
  else
  {
    cout << "NO" << endl ;
  }
  
}
