#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (auto &i : A) cin >> i;
  
  sort(A.begin(), A.end());
  cout << A[N-1] - A[0] << endl;
}