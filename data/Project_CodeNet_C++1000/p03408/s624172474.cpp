#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <string> s(N);
  rep(i,N) cin >> s[i];

  int M;
  cin >> M;
  vector <string> t(M);
  rep(i,M) cin >> t[i];


  int ans = 0;

  rep(i,N){
    int score = 0;
    rep(j,N) if (s[j]==s[i]) score++;
    rep(j,M) if (t[j]==s[i]) score--;

    ans = max(ans, score);
  }

  cout << ans << endl;

}
