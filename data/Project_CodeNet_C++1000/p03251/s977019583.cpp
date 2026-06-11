#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

int main() {
  int a,b,c,d,x,y,tmp;
  cin >> a >> b >> c >> d;
  x = c,y=d;
  rep(i,a){
    cin >> tmp;
    x = max(x,tmp+1);
  }
  rep(i,b){
    cin >> tmp;
    y = min(y,tmp);
  }
  if(x==c) cout << "War";
  else if(y>=x)cout << "No War";
  else cout << "War";
}
