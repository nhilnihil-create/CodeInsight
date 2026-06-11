#include <iostream>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

const int big = 10000;
int main(){
  int n, T;
  cin >> n >> T;
  int cost = big;
  rep(i, n){
    int s, t;
    cin >> s >> t;
    if (t <= T) cost = min(cost, s);
  }
  if (cost == big) cout << "TLE" << endl;
  else cout << cost << endl;
  
  return 0;
}