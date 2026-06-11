
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
int main() {
  int N;
  cin >> N;
  int K;
  cin >> K;
  string S;
  cin >> S;
  S[K -1] = S[K - 1] + 0x20;
  cout << S << endl;
}