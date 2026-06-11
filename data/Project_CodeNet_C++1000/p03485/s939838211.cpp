#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a;
  cin >> b;
  int answer;
  int r = (a + b) % 2;
  if (r == 0) {
    answer = (a + b) / 2;
  } else {
   	answer = (a + b) / 2 + 1;
  }
  cout << answer << endl;
}
