#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i,h) cin >> s.at(i);

  vector<int> x = {-1, 0, 1};
  vector<int> y = {-1, 0, 1};

  vector<vector<int>> ans(h, vector<int>(w,-1));

  rep(i, h){
    rep(j,w){
      if(s.at(i).at(j)=='#') continue;
      int count=0;
      rep(dx, 3){
        rep(dy, 3){
          int nowx = i+x.at(dx);
          int nowy = j+x.at(dy);
          if(nowx>=0&&nowx<h&&nowy>=0&&nowy<w&&s.at(nowx).at(nowy)=='#')count++;
        }
      }
      ans.at(i).at(j) = count;
    }
  }

  rep(i,h){
    rep(j,w){
      if(ans.at(i).at(j)==-1)cout<<'#';
      else cout<<ans.at(i).at(j);
    }
    cout << endl;
  }
  
}