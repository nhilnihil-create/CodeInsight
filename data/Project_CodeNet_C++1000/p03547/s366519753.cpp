#include <bits/stdc++.h>
using namespace std;
 
int main() {

  char X,Y;

  cin >> X >> Y ;

  int x=(int)(X-'A'),y=(int)(Y-'A'); 

  if(x>y) cout << '>' << endl;

  else if(x<y) cout << '<' << endl;

  else cout << '=' << endl;
}