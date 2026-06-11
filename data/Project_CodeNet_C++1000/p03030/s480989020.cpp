#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<pair<string, pair<int, int>>> vec(N);
  rep(i, N) {
    cin >> vec.at(i).first >> vec.at(i).second.first;
    vec.at(i).second.second = i + 1;
    vec.at(i).second.first *= -1;
  }
  sort(vec.begin(), vec.end());
  rep(i, N) {
    cout << vec.at(i).second.second << endl;
  }
}