#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, M;
  cin >> N >> M;
  vector<vector<int>> a(M);
  for(int i = 0; i < M; i++){
    int k;
    cin >> k;
    a.at(i).resize(k);
    for(int j = 0; j < k; j++){
      cin >> a.at(i).at(j);
      a.at(i).at(j)--;
    }
  }
  
  vector<int> p(M);
  for(int i = 0; i < M; i++){
    cin >> p.at(i);
  }
  
  int ans = 0;
  for(int i = 0; i < (1 << N); i++){
    bool f = true;
    for(int j = 0; j < M; j++){
      int c = 0;
      for(int id : a.at(j)){
        if((i >> id) & 1){
          c++;
        }
      }
      c %= 2;
      if(c != p.at(j)){
        f = false;
      }
    }
    if(f) ans++;
  }
  cout << ans << endl;
  return 0;
}