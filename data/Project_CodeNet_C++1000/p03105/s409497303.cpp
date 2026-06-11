#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin >> a >> b >> c;
  d=b%a;
  cout << min((b-d)/a, c) << endl;
}
  