#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for(int i=0; i<h; ++i){
    cin >> mp[i];
  }
  bool ans = true;
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      if(mp[i][j] == '.') continue;
      bool nans = true;
      if(i && mp[i-1][j] == '#') nans = false;
      if(i!=h-1 && mp[i+1][j] == '#') nans = false;
      if(j && mp[i][j-1] == '#') nans = false;
      if(j!=w-1 && mp[i][j+1] == '#') nans = false;
      if(nans) ans = false;
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}