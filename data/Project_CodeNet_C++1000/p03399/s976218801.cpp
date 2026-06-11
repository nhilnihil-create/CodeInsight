#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
 
int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << min(A, B) + min(C, D) << endl;
}