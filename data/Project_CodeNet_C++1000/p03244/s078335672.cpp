#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int n;
  cin >> n;
  vector <int> v(n);
  rep(i,n) cin >> v[i];

  //一次元配列で実装する
  //値iの回数をa[i]に入れる
  vector <int> a(100100);
  vector <int> b(100100);
  rep(i,n){
    if (i % 2 == 0) a[v[i]] ++;
    else b[v[i]] ++;
  }

  int max_a, max_b;  //最大値のindex
  max_a = max_element(a.begin(), a.end()) - a.begin();
  max_b = max_element(b.begin(), b.end()) - b.begin();

  //aでの最頻値とbでの最頻値が異なる場合
  if (max_a != max_b) cout << n - a[max_a] - b[max_b] << endl;
  //aでの最頻値とbでの最頻値が同じ場合
  //降順にソートする
  else{
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  //aの最頻値を残す場合の答え
  int ans_a = n - a[0] - b[1];
  //bの最頻値を残す場合の答え
  int ans_b = n - a[1] - b[0];
  cout << min(ans_a, ans_b) << endl;
  }
  return 0;
}
