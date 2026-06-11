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
  int n; cin >> n;
  vector<int> a(3);
  while(1){
    int now = n;
    rep(i,3){
      a[i] = now % 10;
      now /= 10;
    }
    if(a[0] == a[1] && a[1] == a[2]){
      cout << n << endl;
      return 0;
    }
    n++;
  }
  return 0;
}
