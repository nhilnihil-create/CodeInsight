#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  vector<int> antennas(5);
  int N;
  cin >> N;
  vector<int> monster(N);
  for (int i = 0; i < N; i++) {
    cin >> monster[i];
  }
  for(int i = 1; i < N; i++){
    monster[0] = __gcd(monster[0], monster[i]);
  }
  cout << monster[0] <<endl;
}