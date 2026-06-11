#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, X;
  vector<int> m(N);
  cin >> N >> X;
  int sum = 0;
  int mini = 1000000000;
  for(int i = 0; i < N; i++){
    cin >> m.at(i);
  }
  for(int i = 0; i < N; i++){
    sum += m.at(i);
    mini = min(mini, m.at(i));
  }
  cout << N + (X - sum)/mini << endl;
}
    
    