#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(abs(c-a)<=d||(abs(b-a)<=d&&abs(b-c)<=d))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}