#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  vector<int> card(3);
  for(int i = 0; i < 3; i++) cin >> card[i];
  sort(card.begin(), card.end());
  cout << card[0] + card[1] + card[2] * 10 <<endl;
}
