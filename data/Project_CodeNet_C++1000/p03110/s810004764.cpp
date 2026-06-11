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
  double jpy = 0, btc = 0;
  rep(i,n){
    double x;
    string s;
    cin >> x >> s;
    if(s == "JPY") jpy += x;
    else btc += x;
  }
  double x = btc * 380000.0;
  double ans = x + jpy;
  printf("%.10f\n%", ans);
  return 0;
}
