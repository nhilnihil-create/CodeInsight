#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MAX=INT_MAX;

int main(){
  int h,w;
  std::cin >> h>>w;

  std::vector<std::vector<char> > area(h,std::vector<char>(w));
  rep(i,h)rep(j,w)std::cin >> area[i][j];

  bool ok=true;

  int dh[4]={1,-1,0,0};
  int dw[4]={0,0,1,-1};
  rep(i,h)rep(j,w){
    if(area[i][j]=='.')continue;
    bool n=false;
    rep(k,4){
      if(i+dh[k]<0 || j+dw[k]<0 || i+dh[k]>=h || j+dw[k]>=w)continue;
      if(area[i+dh[k]][j+dw[k]]=='#')n=true;
    }
    if(n==false){
      ok=false;
    }
  }


  if(ok)std::cout << "Yes" << '\n';
  else std::cout << "No" << '\n';


  return 0;
}
