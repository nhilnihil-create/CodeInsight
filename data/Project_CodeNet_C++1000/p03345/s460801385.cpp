#include <iostream>
#define ll long long
using namespace std;

int main() {
  ll a,b,c;
  string k;
  // t = a, n = b, h = c
  cin >> a >> b >> c >> k;

  int f = k[(k.length() - 1)] - '0';

  if (f%2 == 0){
    cout << a-b << endl;
  }
  else{
    cout << b-a << endl;
  }
}