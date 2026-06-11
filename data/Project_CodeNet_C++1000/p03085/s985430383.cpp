#include <iostream>
using namespace std;

int main() {
  char b;
  cin >> b;  
  char ans;
  if(b=='A') ans='T';
  if(b=='T') ans='A';
  if(b=='C') ans='G';
  if(b=='G') ans='C';
  

  cout << ans << endl;

  return 0;
}
