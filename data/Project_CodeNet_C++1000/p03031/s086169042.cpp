#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> s(M, vector<int>(N));
  rep(i, M){
    int k;
    cin >> k;
    s.at(i).resize(k);
    rep(j, k){
      cin >> s.at(i).at(j);
    }
  }
  vector<int> p(M);
  rep(i, M){
    cin >> p.at(i);
  }
  int ans = 0;
  for(int tmp=0; tmp<(1<<10); tmp++){
    bitset<10> o(tmp);
    bool x = true;
    rep(i, M){
      int on = 0;
      rep(j, s.at(i).size()){
        if(o.test(s.at(i).at(j)-1)){
          on++;
        }
      }
      if(on%2!=p.at(i)){
        x = false;
        break;
      }
    }
    if(x){
      ans++;
    }
  }
  int m = 1;
  rep(i, 10-N){
    m *= 2;
  }
  cout << ans/m;
  return 0;
}