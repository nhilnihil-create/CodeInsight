#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(n); i++)//第一引数の変数をカウンタ変数としてn回回す
//repはカウンタ変数が1ずつ増える場合にしか使えない
int INF = 10101010;
using veci = vector<int>;
using vecd = vector<double>;
int main(){//まず全種類のドーナツを作り、次に使用する粉が最も少ないものを調べ、それの
  //使用する粉の量で残った粉の量を割る
  int n, x;
  cin >> n >> x;
  int min_p = INF;
  int ans;
  rep(i, n){
    int a;
    cin >> a;
    min_p = min(a, min_p);
    x -= a;
    ans++;
  }
  int y = x/min_p;
  ans += y;
  cout << ans << endl;
}