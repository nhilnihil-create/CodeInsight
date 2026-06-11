#include <bits/stdc++.h>
using namespace std;
// for (int i = 0, i < N, i++) {
// strint'', char'
// エスケープシークエンス改行になる\n　cout << "こんにちは\nAtCoder";
// 行全て取り出す　getline(cin, 文字列変数);
// int型 data[要素数]; // Cの配列
// 逆順に並び替え　reverse(配列変数.begin(), 配列変数.end());
// 小さい順に並び替え　sort(配列変数.begin(), 配列変数.end());
// 関数定義　返り値の型 関数名(引数1の型 引数1の名前, 引数2の型 引数2の名前, ...) {
// 関数定義はmain関数の前で行うこと, 返り値はreturn
// 範囲for文_配列(stringもおk)の要素を全て取り出す　for (配列の要素の型 変数名 : 配列変数) {
// =========配列===========
// 配列　vector<型> vec(要素数, 初期値);　　vec.at(i)　　vec.size()
// 2次元配列　vector<vector<要素の型>> 変数名(要素数1(行数), vector<要素の型>(要素数2(列数), 初期値));
// 2次元配列　変数名.at(添字1_行).at(添字2_列)
// ジャグ配列(行ごとに要素数が異なる)も可能
// 3次元配列　vector<vector<vector<要素の型>>> 変数名(要素数1, vector<vector<要素の型>>(要素数2, vector<要素の型>(要素数3, 初期値)));
// 配列の末尾に追加　配列名.push_back(要素)
// 参照はむずい2-4をよく読むこと　参照先の型 &参照の名前 = 参照先;
// 参照渡しは高速化に重要
// 後再帰もむずい
// int64_t 末尾にLLをつけるとint64_tとして扱われる
// double型の出力　cout << fixed << setprecision(桁数);
// キャスト(型変換)　(double)a　aをdouble型に
// ========printfでの出力========
// printf("x = %d, pi = %lf\n", x, pi);
// 出力 x = 12345, pi = 3.141593
// フォーマット指定子 int %d　int64_t %ld　double %lf　char %c
// string型出力　printf("%s\n", s.c_str());
// ========scanfでの入力=======
// scanf("x = %d, pi = %lf", &x, &pi);
// 入力 x = 12345, pi = 3.141593
// 数値から文字列 to_string(変数名)
// 文字列から, int stoi(変数名)　int64_t stoll(変数名)　double stod(変数名)
// ========pair===============
// 宣言と初期化 pair<型1, 型2> 変数名(値1, 値2);
// アクセス 変数名.first   // 1つ目の値　変数名.second  // 2つ目の値
// pairの生成 make_pair(値1, 値2)
// pairの分解(以下3行)
// 型1 変数1;
// 型2 変数2;
// tie(変数1, 変数2) = pair型の値;
// =========tuple==============
// pairは値が2つに対して, tupleは値が3つ以上
// アクセス get<K>(tuple型の変数)  // K(定数)番目にアクセス
// 他はpairと同様
// pairとtupleの比較はまず一番目が最優先され, 等しい場合は2番目以降となる. sortなども同様
// autoとignoreは省略
// =========型エイリアス========
// using pii = pair<int, int>;
// これ以降 pii という型名はpair<int, int> と同じ意味で使える
// using vi = vector<int>; // intの1次元の型に vi という別名をつける
// using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
// int N = 10, M = 20;
// vvi data(N, vi(M));  // N * M の2次元配列
// typedefも同様に使える







int main() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    string s;
    int p;
    cin >> s >> p;
    vec.at(i) = make_tuple(s, 100-p, i+1);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) {
    cout << get<2>(vec.at(i)) << endl;
  }
    
}

