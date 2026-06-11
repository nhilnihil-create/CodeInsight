#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

int main(){
  int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;

  int x = x2-x1;
  int y = y2-y1;
  int x3 = x2 - y;
  int y3 = y2 + x;
  int x4 = x1 - y;
  int y4 = y1 + x;
  cout << x3 << " " << y3 << " ";
  cout << x4 << " " << y4 << endl;
  return 0;
}
