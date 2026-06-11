#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int a,b;
  cin >> a >> b;
  if(b%a==0)
  cout << a+b << endl;
  else
  cout << b-a << endl;
}
