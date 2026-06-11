#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  int t = 0;
  cin >> A >> B;
  string s, sr;
  for (int i = A; i <= B; i++) {
    s = to_string(i);
    sr = s;
    reverse(sr.begin(), sr.end());
    if (s == sr){
      t++;
    }
  }
  cout << t << endl;
}