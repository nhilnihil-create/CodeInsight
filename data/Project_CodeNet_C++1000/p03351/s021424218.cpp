#include <bits/stdc++.h>
using namespace std;

int main() {
  long a,b,c,d;
  cin >> a >> b >> c >> d;
  if(labs(a-b)<=d&&labs(b-c)<=d) cout << "Yes" << endl;
  else if(labs(a-c)<=d) cout << "Yes" << endl;
  else cout << "No" << endl;
}