#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  for (auto &i : m) cin >> i;
  
  int res = X - accumulate(m.begin(), m.end(), 0);
  
  sort(m.begin(), m.end());
  int NUM = res / m[0];
  
  cout << N + NUM << endl;
}