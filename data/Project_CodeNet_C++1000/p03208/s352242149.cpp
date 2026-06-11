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
  int N, K;
  cin >> N >> K;
  vector<long long> tree(N);
  for(int i = 0; i < N; i++) cin >> tree[i];
  sort(tree.begin(), tree.end());
  long long Min = 9999999999;
  for(int i = 0; i + K - 1< N; i++){
    Min = min(Min, tree[i+K-1] - tree[i]);
  }
  cout << Min <<endl;
}
