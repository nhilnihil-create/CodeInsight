/*
　　　　　　 ＿＿
　　　　　／＞　　 フ
　　　　　| 　_　 _ l
　 　　　／` ミ＿xノ
　　 　 /　　　 　 |　見ちゃだめだよ！
　　　 /　 ヽ　　 ﾉ　　
　 　 │　　|　|　|　　
　／￣|　　 |　|　|
　| (￣ヽ＿_ヽ_)__)
　＼二つ
*/

#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int total = pow(3, n);
  int total2 = 1;
  //偶数だったら1通り
  rep(i, n) if (a[i] % 2 == 0) total2 *= 2;
  cout << total - total2 << endl;
}