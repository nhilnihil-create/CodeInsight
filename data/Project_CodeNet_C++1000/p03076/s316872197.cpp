#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  vector<int> m(5);
  rep(i,5) cin >> m[i];
  int id = 0;
  int mx = 10 - (m[0] % 10);
  if(mx == 10) mx = 0;
  rep(i,5){
    int temp = 10 - (m[i] % 10);
    if(temp == 10) temp = 0;
    if(temp > mx){
      mx = temp;
      id = i;
    }
  }
  int ans = 0;
  rep(i,5){
    if(i == id) continue;
    if(m[i] % 10 == 0) ans += m[i];
    else{
      int temp = m[i] / 10;
      temp += 1;
      temp *= 10;
      ans += temp;
    }
  }
  ans += m[id];
  cout << ans << endl;
  return 0;
}
