#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end();
int main() {
  string a;
  int flag = 0,co=-1;
  cin >> a;
  if(a.at(0)!='A') flag = 1;
  for(int i = 1;i<a.size();i++){
    if(a.at(i)=='C') {
      if(co!=-1)flag = 1;
      if(i<2||i==a.size()-1)flag=1;
      co = i;
    }
    else if(a.at(i)<'a') flag = 1;
  }
  if(co==-1)flag = 1;
  if(flag) cout << "WA";
  else cout << "AC";
}
