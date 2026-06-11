#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i=0; i<h; ++i) cin >> s[i];
  vector<string> ans(h);
  for(int i=0; i<h; ++i) for(int j=0; j<w; ++j){
    if(s[i][j] == '#'){
      ans[i] += '#';
      continue;
    }
    char c = '0';
    if(i>0 && j>0 && s[i-1][j-1] == '#') ++c;
    if(i>0 && s[i-1][j] == '#') ++c;
    if(i>0 && j<w-1 && s[i-1][j+1] == '#') ++c;
    if(j>0 && s[i][j-1] == '#') ++c;
    if(j<w-1 && s[i][j+1] == '#') ++c;
    if(i<h-1 && j>0 && s[i+1][j-1] == '#') ++c;
    if(i<h-1 && s[i+1][j] == '#') ++c;
    if(i<h-1 && j<w-1 && s[i+1][j+1] == '#') ++c;
    ans[i] += c;
  }
  for(int i=0; i<h; ++i){
    cout << ans[i] << endl;
  }
}