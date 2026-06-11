#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a = 0,b=0,c=0,d=0,e;
  cin >> e;
  char tmp;
  rep(i,e){
    cin >> tmp;
    if(tmp=='P') a=1;
    if(tmp=='W') b=1;
    if(tmp=='G') c=1;
    if(tmp=='Y') d=1;
  }
  int f = a+b+c+d;
  if(f==3)cout << "Three";
  else cout << "Four";
}