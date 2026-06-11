// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <bitset>
using namespace std;

#define ll long long
#define ld long double
#define pi 3.14159265359;
// %llu %lf

// v:vector  type:型  order:greater(大きい順) or less(小さい順)
#define _sort(v,type,order) do { sort(v.begin(),v.end(),order<type>()); } while(0)
// vector 要素の総和算出
// v:vector  default_value:初期値
#define _sum(v,default_value) accumulate(v.begin(),v.end(),default_value )
// vector 最大値( return ite )
#define _max_element(v) max_element(v.begin(),v.end())
// vector 最小値( return ite )
#define _min_element(v) min_element(v.begin(),v.end())
// vector 最大値が格納されている要素値
#define _max_element_number(v) distance(v.begin(),max_element(v.begin(),v.end()))
// 特定コンテナの中から特定の値をカウントする
#define _count(v,value) count(v.begin(),v.end(),value)

//set<uint32_t> member;	// 重複するデータを保持する事はできない member.insert(2) member.insert(2) ⇒ member.count(2)は1
//                                                              member.emplace(2)とかも同じ
//multiset<uint32_t> v;	// 重複するデータも保持する事はできる   member.insert(2) member.insert(2) ⇒ member.count(2)は2

// 丸め
#define _round(v) round(v)
// 2乗 / 3乗
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)
// 大小判定
#define _max(x,y) max(x,y)
#define _min(x,y) min(x,y)
// string ⇒ int
#define _stringtoi(s) stoi(s)
// double 平方根
#define _sqrt(x) sqrt(x)
// double 引数 x 以上で最小の整数値 ex) 3.30303 ⇒ 4
#define _ceil(x) ceil(x)
// 指定された要素以上の値が現れる最初の位置のイテレータを取得する
#define _lower_bound(v,min) lower_bound(v.begin(), v.end(), min)
// 指定された要素より大きい値が現れる最初の位置のイテレータを取得する
#define _upper_bound(v,min) upper_bound(v.begin(), v.end(), min)

// 順列 n個の数が与えられる
// 0,1,2,...,n-1
// 全ての並べ方を1行ごとに出力する
// ex 0 1 2 / 0 2 1 / 1 0 2 / 1 2 0 / 2 0 1 / 2 1 0
#define _next_permutation(v) do {   \
	for (auto num : v) {            \
		printf("%d ", num);         \
	}                               \
	printf("\n");                   \
} while (next_permutation(v.begin(), v.end()))

// 絶対値
template<typename T>
static T _abs(const T x) { return  (x > 0 ? x : -x); }

// 最大公約数
int64_t gcd(int64_t a, int64_t b) { while (b) { int64_t c = b; b = a % b; a = c; } return a; }
// 最小公倍数
int64_t lcm(int64_t a, int64_t b) { if (!a || !b) return 0; return a * b / gcd(a, b); }

// 多次元 std::vector 生成
template<class T>
vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts) { return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...)); }
// ex) auto dp = make_vec<uint64_t>(SIZE + 1, 2, 2);

// Union Find Tree
struct union_find_t
{
	// par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
	vector<int> par;

	//最初は全てが根であるとして初期化
	union_find_t(int N) : par(N) { for (int i = 0; i < N; i++) par[i] = i; }

	// データxが属する木の根を再帰で得る：root(x) = {xの木の根}
	int root(int x)
	{
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	// xとyの木を併合
	void unite(int x, int y)
	{
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	// 2つのデータx, yが属する木が同じならtrueを返す
	bool same(int x, int y) { return (root(x) == root(y)); }
#if 0
	{
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
#endif

};


// ■
// UINT32_MAX
// 4294967295 ≒ 4 * 1e9

// ■
// 割り算した結果との比較での丸め対処時 
// ABC 161 B
// https://atcoder.jp/contests/abc161/tasks/abc161_b
// double   border = _sum(v, 0 / (double)(4 * m);
//            ↓
// uint32_t border = (_sum(v, 0) + (4 * m) - 1) / (4 * m);

/*************************************************************/
// ABC 097
// D - Equals
// https://atcoder.jp/contests/abc097/tasks/arc097_b
/*
	■問題文
	1 から N までの整数を並び替えた順列 p1, p2, .., pN があります。 
	また、 1 以上 N 以下の整数のペアが M 個与えられます。 
	これらは (x1,y1), (x2,y2), .., (xM,yM) で表されます。 
	シカの AtCoDeer くんは順列 p に次の操作を好きなだけ行って、 pi=i となる i (1 ≤ i ≤ N ) の数を最大にしようと考えています。

    ・1 ≤ j ≤ M なる j を選び、 pxj と pyj をスワップする

	操作後の pi=i となる i の数として考えうる最大値を求めてください。

	■制約

	■入力
	N M
	p1 p2 .. pN
	x1 y1
	x2 y2
	:
	xM yM

	操作後の pi=i となる i (1 ≤ i ≤ N) の数として考えうる最大値を出力せよ。

	■入力例
	5 2
	5 3 1 4 2
	1 3
	5 4

	■出力例
	2
	j = 1 を選んで操作すると、 p は 1 3 5 4 2 となり、これがベストなので答えは 2 です。
*/

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> P(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	union_find_t tree(N);
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		tree.unite(x - 1, y - 1); // x-1の木とy-1の木を併合する
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (tree.same(i, P[i] - 1)) { //iとP[i]-1が同じ木に属するなら，カウンタに1追加
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
