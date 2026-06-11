#include<bits/stdc++.h>

using namespace std;

int main(void){
  int a, b, c;
  cin >> a >> b >> c;
  
  if(a != b && b == c) cout << a << endl;
  else if(a != b && b != c) cout << b << endl;
  else cout << c << endl;
}