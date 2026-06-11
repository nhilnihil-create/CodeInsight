#include <bits/stdc++.h>
using namespace std;

int main(){
  int c, a, b;
  cin >> c >> a >> b;
  
  int s = (c + a + b) / 2.0;
  
  cout << pow(s * (s - a) * (s - b) * (s - c), 0.5) << endl;
}