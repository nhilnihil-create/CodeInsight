#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;

  //iはケーキ、jはドーナツの個数
  string ans = "No";
  for (int i = 0; i <= N / 4; i++){
    if ((N - 4 * i) % 7 == 0) ans = "Yes";
  }
  cout << ans << endl;
}
