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
  string s; cin >> s;
  int ans = 1<<29;
  rep(i,s.size()-2){
    int now = 0;
    rep(j,3){
      now *= 10;
      now += s[i+j] - '0';
    }
    int temp = abs(753-now);
    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}
