#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double a, b, answer;
  cin >> a >> b;
  answer = (a + b) / 2;
  answer = (int)answer + (answer - (int)answer) * 2;
  cout << answer << endl;
}