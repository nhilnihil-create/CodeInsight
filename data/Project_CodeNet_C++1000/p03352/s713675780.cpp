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
  vi a(1001,0);
  a.at(1) = 1;
  for(int i = 2;i<sqrt(1001);i++){
    int j = i*i;
    while(j<1001){
    a.at(j) = 1;
    j *= i;
    }
  }
  int b;
  cin >> b;
  for(int i = b;i>0;i--){
    if(a.at(i)==1){
      cout << i;
      break;
    }
  }
}