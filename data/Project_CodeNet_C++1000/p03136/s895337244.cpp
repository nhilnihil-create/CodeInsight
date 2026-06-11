#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int sum = 0;
  rep(i, N) {
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  if(vec.at(0) < sum - vec.at(0)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}