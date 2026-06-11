#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  for(int i = 0; i < N; i++){
    cin >> m.at(i);
    X -= m.at(i);
  }
  sort(m.begin(), m.end());
  cout << N + X / m.at(0);
  return 0;
}
