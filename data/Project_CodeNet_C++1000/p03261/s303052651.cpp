#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  //input
  int N;
  cin >> N;
  vector <string> W(N);
  rep(i,N) cin >> W[i];

  //solve
  set<string> s;
  s.insert(W[0]);
  string ans = "Yes";

  for (int i = 1; i < N; i++){
    if (s.count(W[i]) == 1) ans = "No";
    int len = W[i - 1].size();
    if (W[i][0] != W[i - 1][len - 1]) ans = "No";
    s.insert(W[i]);
  }

  //output
  cout << ans << endl;
}
