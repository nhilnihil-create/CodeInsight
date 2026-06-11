#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

string six_fix(int a) {
  string str = to_string(a);
  while ((int)str.size() != 6) {
    str = '0' + str;
  }
  return str;
}

int main() {
  int N,M;
  cin >> N >> M;
  int p[M],Y[M];
  vector<P> A[110000];
  string ans[M];
  for (int i = 0; i < M; i++) {
    cin >> p[i] >> Y[i];
    A[p[i]].emplace_back(Y[i],i);
  }
  for (int i = 0; i < 110000; i++) {
    sort(A[i].begin(),A[i].end());
  }
  for (int i = 0; i < 110000; i++) {
    for (int j = 0; j < (int)A[i].size(); j++) {
      ans[A[i][j].S] = six_fix(i) + six_fix(j+1);
    } 
  }
  for (int i = 0; i < M; i++) {
    cout << ans[i] << endl; 
  }
  return 0;
}