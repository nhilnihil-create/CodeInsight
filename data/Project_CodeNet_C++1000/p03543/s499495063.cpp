#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, s;
  cin >> N;
  s = N/10%10;
  if(s != N/100%10) cout << "No";
  else if(s == N%10 || s == N/1000%10) cout << "Yes";
  else cout << "No";
}
