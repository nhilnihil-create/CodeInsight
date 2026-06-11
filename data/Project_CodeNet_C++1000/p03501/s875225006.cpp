#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
 
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  cout << min(A * N, B) << endl;
}