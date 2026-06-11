#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
 
int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int left = A + B;
  int right = C + D;
  if(left > right) cout << "Left";
  else if(left == right) cout << "Balanced";
  else cout << "Right";
  cout << endl;
}