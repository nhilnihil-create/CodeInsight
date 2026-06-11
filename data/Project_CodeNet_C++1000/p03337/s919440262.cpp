
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
int main() {
  int A, B;
  cin >> A >> B;
  cout << max(A+B, max(A-B, A * B)) << endl;
}