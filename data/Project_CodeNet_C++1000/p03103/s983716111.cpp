#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<pair<int64_t,int64_t>> vec(N);
  for (int i =0; i<N; i++) {
    int64_t O,P;
    cin >> O >> P;
    vec.at(i) = make_pair(O,P);
  }
  sort(vec.begin(), vec.end());
  int64_t total =0;
  int64_t ans =0;
  int i =0;
  bool shokai =false;
  while (true) {
    if (vec.at(i).second >= M) {
      shokai =true;
      break;
    } else {
      total += vec.at(i).second;
      ans += vec.at(i).first * vec.at(i).second;
      if (total + vec.at(i+1).second >= M) {
        break;
      } else {
        i++;
      }
    }
  }
  if (shokai) {
    ans += (M - total) * vec.at(i).first;
  } else {
    ans += (M - total) * vec.at(i+1).first;
  }
  cout << ans << endl;
}