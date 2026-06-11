#include <bits/stdc++.h>
using namespace std;

int main() {
int a, b, c, d;
  cin >> a >> b >> c >>d;
  if(max(a-b, b-a)<=d && max(b-c, c-b)<=d) cout <<"Yes" << endl;
  else if(max(a-c, c-a) <= d) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
