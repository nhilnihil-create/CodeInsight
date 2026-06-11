#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<=(n); i++)//第一引数の変数をカウンタ変数としてn回回す
//repはカウンタ変数が1ずつ増える場合にしか使えない
int INF = 10101010;
using veci = vector<int>;
using vecd = vector<double>;
int main(){//それぞれの枚数について固定してよいので全探索する
  int a, b, c, x;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> x;
  int count=0;
  rep(i, a){
    rep(j, b){
      rep(h, c){
        if ((500*i) + (100*j) + (50*h) == x){
          count++;
        }
      }
    }
  }
  cout << count << endl;
}