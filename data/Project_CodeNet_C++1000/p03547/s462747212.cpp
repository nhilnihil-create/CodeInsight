#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  char x,y;
  cin >> x >> y;
  if(x==y)
    cout << "=" << endl;
  else if(x>y)
    cout << ">" << endl;
  else
    cout << "<" << endl;
}