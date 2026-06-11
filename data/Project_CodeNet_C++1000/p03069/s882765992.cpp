#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int n;
string s;

int main(){
  cin >> n >> s;
  int bnum[n + 1]; //左側の黒の数
  bnum[0] = 0;
  for(int i = 0; i < n; i++){
    bnum[i + 1] = bnum[i];
    if(s.at(i) == '#'){
      bnum[i + 1]++;
    }
  }
  //rep(i, n + 1) cerr << bnum[i] << " "; cerr << endl;
  int wnum[n + 1]; //右側の白の数
  wnum[n] = 0;
  for(int i = n - 1; i >= 0; i--){
    wnum[i] = wnum[i + 1];
    if(s.at(i) == '.'){
      wnum[i]++;
    }
  }
  //rep(i, n + 1) cerr << wnum[i] << " "; cerr << endl;
  int res = 1e9;
  for(int i = 0; i <= n; i++){
    res = min(bnum[i] + wnum[i], res);
  }
  cout << res << endl;
  return 0;
}
