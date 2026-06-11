#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  int M = 0, sum = 0;
  for(int i = 0; i < N; i++){
    cin >> a.at(i);
    M = max(M, a.at(i));
    sum += a.at(i);
  }
  cout << sum - M/2 << endl;
}