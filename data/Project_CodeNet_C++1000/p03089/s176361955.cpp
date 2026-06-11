#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> b(N);
  rep(i, N) cin >> b[i];
  reverse(b.begin(), b.end());
  int i = 0;
  vector<int> ans;
  while(!b.empty()){
    i = 0;
    bool erase = false;
    for(auto it = b.begin(); it != b.end(); it++){
      if(*it == b.size() - i){
        ans.push_back(*it);
        b.erase(b.begin() + i);
        erase = true;
        break;
      }
      ++i;
    }
    if(!erase){
      cout << -1 << endl;
      return 0;
    }
  }

  for(int i = 0; i < ans.size(); ++i){
    cout << ans[ans.size() - 1 - i] << endl;
  }
  return 0;
}