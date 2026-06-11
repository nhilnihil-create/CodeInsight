#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long N, A, B, C, D, E;
  cin >> N >> A >> B >> C >> D >> E;
  
  cout << (N+min({A,B,C,D,E})-1)/min({A,B,C,D,E}) + 4LL << endl;

  return 0;
}
