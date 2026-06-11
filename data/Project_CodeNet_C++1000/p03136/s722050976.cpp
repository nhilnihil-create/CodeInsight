#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, max, sum = 0;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  max = vec.back();
  for(int i = 0; i < N - 1; i++) sum += vec[i];
  if(sum > max) cout << "Yes" << endl;
  else cout << "No" << endl;
}