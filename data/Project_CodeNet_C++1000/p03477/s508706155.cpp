#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z, u;
  cin >> x >> y >> z >> u;

 if ( x + y > z + u ) {
   cout << "Left" << endl;
 }
  else if ( x + y == z + u ) {
    cout << "Balanced" << endl;
 }
  else if( x+ y < z+ u ) {
    cout << "Right" << endl;
 }
}
