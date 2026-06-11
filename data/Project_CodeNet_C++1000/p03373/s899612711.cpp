#include<bits/stdc++.h>
using namespace std;

int main(){
  // std::ifstream in("input.txt");
  // std::cin.rdbuf(in.rdbuf());

  int64_t A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int64_t min_cost = 1LL << 60;
  for(int i=0; i<=max(X, Y); i++){
    int64_t addA = max((int64_t)0, X-i);
    int64_t addB = max((int64_t)0, Y-i);

    int64_t cost = addA * A + addB * B + i * 2 * C;
    min_cost = min(min_cost, cost);
  }

  cout << min_cost << endl;

  return 0;
}