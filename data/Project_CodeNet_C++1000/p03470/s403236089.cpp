#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  rep(i, N) {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  int c = 1;
  rep(i, N - 1) {
    if(vec.at(i) < vec.at(i + 1)) {
      c++;
    }
  }
  cout << c << endl;
}

