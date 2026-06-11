#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,w;
  cin >> h >> w;
  vector<string>data(h);
  rep(i,0,h) cin >> data[i];
  rep(i,0,h) rep(j,0,w){
    if(data[i][j] == '.') continue;
    bool f = 0;
    if(i > 0) if(data[i-1][j] == '#') f = 1;
    if(i < h-1) if(data[i+1][j] == '#') f = 1;
    if(j > 0) if(data[i][j-1] == '#') f = 1;
    if(j < w-1) if(data[i][j+1] == '#') f = 1;
    if(!f){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}