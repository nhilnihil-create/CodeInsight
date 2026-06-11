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
template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

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

// pair
// vector<vector<pair<int32_t,int32_t>>> f(n);
// ⇒ 挿入 f[i].push_back(make_pair(x, y));

// Union Find Tree
class UnionFind
{
public:
	vector <int32_t> par; // 各元の親を表す配列
	vector <int32_t> siz; // 素集合のサイズを表す配列(1 で初期化)

	// Constructor 初期では親は自分自身
	UnionFind(int32_t sz_) : par(sz_), siz(sz_, 1LL) { for (int32_t i = 0; i < sz_; ++i) par[i] = i; }

	void init(int32_t sz_)
	{
		par.resize(sz_);
		siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
		for (int32_t i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}

	// Find
	int32_t root(int32_t x)
	{
		// x の親の親を x の親とする
		while (par[x] != x) {
			x = par[x] = par[par[x]];
			//			printf("%d\n", x);
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(int32_t x, int32_t y)
	{
		x = root(x);
		y = root(y);
		if (x == y) return false;
		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	// 連結判定
	bool is_same(int32_t x, int32_t y) { return root(x) == root(y); }

	// 素集合のサイズ
	int32_t size(int32_t x) { return siz[root(x)]; }

	// 参照
	void view(void) {
		for (size_t i = 0; i < par.size(); i++) {
			printf("%d\n", par[i]);
		}
	}

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
// ABC 104
// C - All Green
// https://atcoder.jp/contests/abc104/tasks/abc104_c
/*
	■問題文
	プログラミングコンペティションサイト AtCode は、アルゴリズムの問題集を提供しています。 
	それぞれの問題には、難易度に応じて点数が付けられています。 
	現在、1 以上 D 以下のそれぞれの整数 i に対して、100i 点を付けられた問題が pi 問存在します。 これらの p1+…+pD 問が AtCode に収録された問題のすべてです。

	AtCode のユーザーは 総合スコア と呼ばれる値を持ちます。 ユーザーの総合スコアは、以下の 2 つの要素の和です。

    ・基本スコア: ユーザーが解いた問題すべての配点の合計です。
    ・コンプリートボーナス: 100i 点を付けられた pi 問の問題すべてを解いたユーザーは、基本スコアと別にコンプリートボーナス ci 点を獲得します (1 ≤ i ≤ D )。

	AtCode の新たなユーザーとなった高橋くんは、まだ問題を 1 問も解いていません。 
	彼の目標は、総合スコアを G 点以上にすることです。 このためには、少なくとも何問の問題を解く必要があるでしょうか？

	■制約
	-

	■入力
	D  G
	p1 c1
	:
	pD cD

	■出力
	総合スコアを G 点以上にするために解く必要のある最小の問題数を出力せよ。なお、この目標は必ず達成可能である（制約を参照のこと）。

	■入力例
	2 700
	3 500
	5 800

	■出力例
	3

	この場合、AtCode には 100 点を付けられた問題が 3 問、200 点を付けられた問題が 5 問あります。
	100 点の 3 問をすべて解いた際のコンプリートボーナスは 500 点、200 点の 5 問をすべて解いた際のコンプリートボーナスは 800 点です。
	高橋くんの目標は総合スコアを 700 点以上にすることです。

	目標を達成する方法の一つは、200 点問題を 4 問解いて 800 点の基本スコアを得ることです。
	しかし、100 点問題を 3 問すべて解くと、基本スコア 300 点に加えてコンプリートボーナスの 500 点が与えられて総合スコアが 800 点となり、より少ない問題数で目標を達成することができます。
*/

#if 0

int main()
{
	int32_t d, g;
	cin >> d >> g;

	vector<pair<int32_t, int32_t>> v(d);
	int32_t p, c;

	int32_t sum = 0;
	for (int32_t i = 0; i < d; i++) {
		cin >> p;
		cin >> c;
		v[i].first = p;
		v[i].second = c;

		sum += p;
	}

	int32_t result = INT32_MAX;
	for (int64_t bits = 1; bits < (1LL << sum); bits++) {
		int32_t temp = 0;
		int32_t score = 0;

		vector<int32_t> cnt(d);

		for (int64_t i = 0; i < sum; i++) {

			if (!(bits & (1LL << i))) { continue; }
			temp++;
			int32_t pos = 0;
			for (int32_t j = 0; j < d; j++) {
				if (i < v[j].first + pos) {
					cnt[j]++;
					score += (j + 1) * 100;
					break;
				}
				pos += v[j].first;
			}
		}

		// スコア比較
		for (int32_t i = 0; i < d; i++) {
			if (cnt[i] < v[i].first) { continue; }
			// ボーナス加算
			score += v[i].second;
		}

		if (score < g) { continue; }
		result = _min(result, temp);
	}

	cout << result << endl;
	return 0;
}

#else

// 上記だとテスト数が多くなると 1eN N=テスト数となり、処理回数が多くなる為 NGだった
// なので for( int32_t bits = 1 ; bits < 1eN ; bits++ ) 箇所を少なくする実装が↓

int main()
{
	int32_t D, G, p[11], c[11];
	cin >> D >> G;

	for (int32_t i = 0; i < D; ++i) {
		cin >> p[i] >> c[i];
	}

	int32_t ans = (int32_t)1e9;
	for (int32_t bits = 0; bits < (1 << D); bits++) {

		int32_t s = 0;
		int32_t num = 0;
		int32_t rest_max = -1;
		for (int32_t i = 0; i < D; ++i) {
			if (bits & (1 << i)) {
				s += 100 * (i + 1) * p[i] + c[i];
				num += p[i];
				continue;
			}
			// 他問題得点を加算していく場合、iが大きい方が点数が高い為、
			// 一番最後の問題を選んでいくスタンスでよい
			rest_max = i;
		}

		// 目標値に到達していなかった場合
		if (s < G) {
			// 他点数を何問か加算していく
			int32_t s1 = 100 * (rest_max + 1);
			// 目標値を超す為に必要な問題数
			int32_t need = (G - s + s1 - 1) / s1;
			// 必要テスト数が足りなかった場合
			if (need >= p[rest_max]) { continue; }
			// あれば加算
			num += need;
		}
		ans = min(ans, num);
	}

	cout << ans << endl;
	return 0;
}

#endif


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
