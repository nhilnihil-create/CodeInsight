#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long ;

int main() {

    char a,b ; 
    cin >> a >> b  ;

    if(a<b)
     cout << '<' ;
    else if(a>b)
     cout << '>' ;
    else 
     cout << '=' ;
    
  cout << endl ;

  return 0 ;
}