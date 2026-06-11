#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B,total;
  cin >> N >> A >> B;
  total = N * A;
  if(total > B)
    cout << B << endl;
  else
    cout << total << endl;
}
