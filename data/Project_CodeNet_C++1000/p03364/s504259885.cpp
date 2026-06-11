#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main(){
  int N;
  cin>>N;
  string s[300];
  for(int i(0);i<N;i++){
    cin>>s[i];
  }
  ll ans(0);
  for(int i(0);i<N;i++){
    bool flag = true;

    for(int i(0);i<N;i++){
      char c = s[i][N-1];
      s[i].pop_back();
      s[i].insert(s[i].begin(),c);
    }
    for(int h(0);h<N;h++){
      for(int w(0);w<h;w++){
        if(s[h][w] != s[w][h]){
          flag = false;
        }
      }
    }
    if(flag) ans += N;
  }
  cout << ans << endl;
  return 0;
}

