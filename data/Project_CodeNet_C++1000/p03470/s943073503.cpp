#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
  int N;
  cin >> N;

  int input;
  vector<int> vec;
  rep (i, N) {
    cin >> input;
    vec.push_back(input);
  }
  sort(vec.begin(), vec.end());
  int ttl = 0;
  int before = -1;
  rep(i, vec.size()) {
    if (before != vec.at(i)) {
      ttl += 1;
    }
    before = vec.at(i);
  }

  cout << ttl << endl;
}
