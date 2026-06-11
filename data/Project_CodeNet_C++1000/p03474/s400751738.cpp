#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,b,flag=0;
  cin >> a >> b;
  string c;
  cin >> c;
  if(c.at(a)!='-') flag = 1;
  rep(i,a+b+1){
    if(i==a) continue;
    if(c.at(i)<'0'||c.at(i)>'9')flag =1;
  }
  if(flag) cout << "No";
  else cout << "Yes";
}