#include<bits/stdc++.h>
using namespace std;

int main() {
  int N,X;
  cin >> N >> X;
  vector<int> M(N);
  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> M.at(i);
    sum += M.at(i); 
  }
  sort(M.begin(),M.end());
  X -= sum;
  int ans = N + X / M.at(0);
  cout << ans << endl;
}