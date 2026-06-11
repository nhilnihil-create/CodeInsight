#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  string S;
  cin >> S;
  int N = S.length();
  int ans1 = 0;
  int ans2 = 0;
  //010...
  vector <int>  black(N);
  for (int i = 1; i < N; i += 2) black[i] = 1;
  //101...
  vector <int>  white(N);
  for (int i = 0; i < N; i += 2) white[i] = 1;
  rep(i,N){
    if (S[i] != char(black[i] + '0')) ans1 ++;
    if (S[i] != char(white[i] + '0')) ans2 ++;
  }
  cout << min(ans1, ans2) << endl;
  return 0;
}
