#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  cout << max(N,max(A,B)) - min(N,min(A,B)) << endl;
}
