#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
 int a, b, d, x;
  cin >> a >> b;
  x = (a + b) / 2;
  d = (a + b) % 2;
  
 int answer;
  answer = x + d;
  cout << answer << endl;
}