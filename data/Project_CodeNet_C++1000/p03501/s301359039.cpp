#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int planA = N * A;
  int planB = B;
  if (planA > planB) {
    cout << planB << endl;
  }
  else {
    cout << planA << endl;
  }
}