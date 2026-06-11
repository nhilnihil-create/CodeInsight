#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n); for (int i=0; i<(n); i++)//第一引数の変数をカウンタ変数としてn回回す
//repはカウンタ変数が1ずつ増える場合にしか使えない
using veci = vector<int>;
using vecd = vector<double>;
using vecs = vector<string>;
int main(){//受け取った数列を昇順にソートして、その分だけ順に減らしていき、その都度ansを1増やす
  int n, x;
  cin >> n >> x;
  veci a(n)
  rep(i, n){
    cin >> a.at(i);
  }
  int ans = 0;
  sort(a.begin(), a.end());
  rep(i, n){
    if (i == n-1 && x != a.at(i)){
      break;
    }
    if (x >= a.at(i)){
      x -= a.at(i);
      ans += 1;
    }
    else{
      break;
    }
  }
  cout << ans << endl;
}