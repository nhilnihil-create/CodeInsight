#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
using Graph = vector<vector<int>>;

int main() {
  //入力
  int N,M;
  cin >> N >> M;
  vector<vector<int>> vec(M); //Mにつけるカッコが()であることに注意
  FOR(i,0,M) {
    int k; cin >> k;
    vec[i].resize(k); //resizeは便利
    FOR(j,0,k) {
      cin >> vec[i][j];
      vec[i][j]--;
    }
  }
  vector<int> p(M); //Mにつけるカッコが()であることに注意
  FOR(i,0,M) cin >> p[i];
  
  //bit探索
  int ans = 0;
  
  for(int bit=0; bit<(1<<N); bit++) {
    bool ok = true; //デフォはtrue(一度でも条件を満たさなかったときにfalseに切り替わる)
    FOR(j,0,M) {
      int c=0;
      for(int id: vec[j]) { //こうすればループ回数を知らなくて良い
        if((bit >> id) & 1) c++; //そのスイッチがオンかどうか
      }
      c %= 2;
      if(c != p[j]) ok = false;
    }
    if(ok) ans++;
  }
  
  cout << ans << endl;
        
  
  
  
  return 0;
}