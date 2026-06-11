#include <bits/stdc++.h>
using namespace std;

template <typename T>
string ToString(const T& n) {
  ostringstream stm;
  stm << n;
  return stm.str();
}

void addZero(string& x) {
  int tmp = 6 - x.size(); 
  for (int i = 0; i < tmp; i++) {
    x.insert(0, "0");
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>> city;
  vector<int> pre(N);
  vector<string> ans(M);
  for (int i = 0; i < M; i++) {
    int p, y;
    cin >> p >> y;
    p--;
    city.emplace_back(y, p, i);
  }
  sort(city.begin(), city.end());
  for (int i = 0; i < M; i++) {
    pre[get<1>(city[i])]++;
    string tmpA = ToString(get<1>(city[i]) + 1);
    addZero(tmpA);
    string tmpB = ToString(pre[get<1>(city[i])]);
    addZero(tmpB);
    ans[get<2>(city[i])] = tmpA + tmpB;
  }
  for (int i = 0; i < M; i++) {
    cout << ans[i] << endl;
  }
}
