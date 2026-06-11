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
  sort(monster.begin(), monster.end());
  while (monster[1] != 0) {
    for (int i = 1; i < monster.size(); i++) {
      monster[i] %= monster[0];
      if(monster[i] == 0){
        monster.erase(monster.begin() + i);
      }
    }
    sort(monster.begin(), monster.end());
  }
  cout << monster[0] << endl;
}