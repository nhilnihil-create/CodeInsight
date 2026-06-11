#include <cmath>
#include <climits>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  int A, B; cin >> A >> B;
  int sc[3] = {};
  for (int i = 0; i < N; ++i) {
    int P; cin >> P;
    if (P <= A)               sc[0]++;
    else if (A < P && P <= B) sc[1]++;
    else if (B < P)           sc[2]++;
  }
  cout << min({sc[0], sc[1], sc[2]}) << endl;
}
