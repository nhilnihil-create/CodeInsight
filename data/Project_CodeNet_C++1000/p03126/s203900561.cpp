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
  int a,b,sum=0;
  cin >> a >> b;
  vi ans(b,0);
  rep(i,a){
    int d;
    cin >> d;
    rep(j,d){
      int e;
      cin >> e;
      e--;
      ans.at(e)++;
    }
  }rep(i,b){
    if(ans.at(i)==a)sum++;
}
cout << sum;
}