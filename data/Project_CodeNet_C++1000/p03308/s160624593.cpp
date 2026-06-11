#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(n); i++)//第一引数の変数をカウンタ変数としてn回回す
using veci = vector<int>;
int main(){
  int n;
  cin >> n;
  veci a(n);
  rep(i, n){
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  ans = max(abs(a.at(0) - a.at(n-1)), abs(a.at(n-1) - a.at(0)));
  cout << ans << endl;
}