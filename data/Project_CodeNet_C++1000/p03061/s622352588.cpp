#include <bits/stdc++.h>
using namespace std;

//セグメント木
//全て添字で扱うこと
struct segment_tree {
  long long n; //vの要素数
  long long m; //葉の数
  vector<long long> v; //セグ木本体．ただの配列を使う
  long long id_e; //単位元

  //二項演算
  long long binary_op(long long a, long long b) {
    return gcd(a,b);//処理
  }

  //初期化関数．数列と単位元を受け取って初期化
  void init(vector<long long> a, long long b) {
    id_e = b;
    m = 1;
    while (m < a.size()) m *= 2; //aの項数以上の2べきのうち最小のものを求める
    n = 2 * m - 1;
    v.resize(n);
    for (long long i = 0; i < a.size(); i++) v[m - 1 + i] = a[i]; //葉(1段目)の値
    for (long long i = a.size(); i < m; i++) v[m - 1 + i] = id_e; //葉(1段目)の右端の0埋め
    for (long long i = m - 2; i >= 0; i--) { //2段目以降を順番に埋めていく
      v[i] = binary_op(v[2 * i + 1], v[2 * i + 2]);
    }
  }

  //ある項の値をbに書き換え
  void change(long long a, long long b) {
    a += m - 1;
    v[a] = b; //葉(1段目)を書き換え
    while ((a - 1) / 2 != a) { //2段目以降を順番に書き換え
      a = (a - 1) / 2;
      v[a] = binary_op(v[2 * a + 1], v[2 * a + 2]);
    }
  }

  //区間和の補助関数
  //cur:今見ている頂点の，配列vでの添字
  //[l, r]:v[cur]がカバーする区間
  long long seg_sub(long long a, long long b, long long cur, long long l, long long r) {
    if (a <= l && r <= b) return v[cur]; //今見ている頂点のカバーする区間が，[a, b]に完全に収まっている場合
    if (r < a || b < l) return id_e; //今見ている頂点のカバーする区間が，[a, b]と全く被っていない場合
    return binary_op( //今見ている頂点のカバーする区間が，[a, b]と一部被っている場合
      seg_sub(a, b, 2 * cur + 1, l, (l + r) / 2),
      seg_sub(a, b, 2 * cur + 2, (l + r) / 2 + 1, r)
    );
  }

  //区間[a, b]の和
  //最上段の頂点から子へ再帰していく
  long long partial_sum(long long a, long long b) {return seg_sub(a, b, 0, 0, m - 1);}
};

int main() {
  long long n;
  cin >> n ;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];

  segment_tree seg;
  seg.init(a, 0);

  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    seg.change(i, 0);
    ans = max(ans, seg.partial_sum(0,n-1));
    seg.change(i, a[i]);
  }
  cout << ans << endl;
}