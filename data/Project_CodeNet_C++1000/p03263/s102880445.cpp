#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  int hw[h][w];
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      cin >> hw[i][j];
    }
  }
  int ans=0;
  vector<tuple<int,int,int,int>> ansv(0);
  for(int i=0; i<h; ++i){
    for(int j=0; j<w-1; ++j){
      if(hw[i][j] %2){
        ++hw[i][j+1];
        ++ans;
        ansv.push_back(make_tuple(i+1,j+1,i+1,j+2));
      }
    }
  }
  for(int i=0; i<h-1; ++i){
    if(hw[i][w-1] %2){
      ++hw[i+1][w-1];
      ++ans;
      ansv.push_back(make_tuple(i+1,w,i+2,w));
    }
  }
  cout << ans << endl;
  for(int i=0; i<(int)ansv.size(); ++i){
    int a, b, c, d;
    a = get<0>(ansv[i]);
    b = get<1>(ansv[i]);
    c = get<2>(ansv[i]);
    d = get<3>(ansv[i]);
    printf("%d %d %d %d\n",a,b,c,d);
  }
}