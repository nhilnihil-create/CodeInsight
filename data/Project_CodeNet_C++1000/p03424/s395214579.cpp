#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ;
  cin >> N ;
  vector <char> c(N) ;
  for ( int i=0 ; i< N ; i++ ) {
    cin >> c.at(i);
    if (c.at(i) == 'Y'){
      cout << "Four"  << endl;
      return 0 ;
  }
  }
    cout << "Three" << endl;
}