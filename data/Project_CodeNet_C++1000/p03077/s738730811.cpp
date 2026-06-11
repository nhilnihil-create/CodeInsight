#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;

int main(){
  ll N;
  ll trans[5];
  cin >> N;
  for (int i = 0; i < 5; i++) cin >> trans[i];
  ll mini = *min_element(trans, trans + 5);
  cout << (N+mini-1)/mini+ 4 << endl;
  return 0;
}