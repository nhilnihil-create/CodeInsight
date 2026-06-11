#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
#include<list>
using namespace std;

struct bridge {
	int vala;
	int valb;
	bridge(int ia, int ib) {
		vala = ia;
		valb = ib;
	}
};

// 数値 vala でソートするための比較演算子
bool cmp(const bridge& a, const bridge& b) {
	return a.vala < b.vala;
}

int main() {

	int N, M;
	cin >> N >> M;

	int a, b;
	vector<bridge> bd;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		bd.push_back(bridge(a, b));
	}

	// 中の悪い島の関係を小さい島の値 a でソート
	sort(bd.begin(), bd.end(), cmp);

	// 貪欲法で橋をなくす必要がある島同士を探索
	vector<int> edgea = { bd[0].vala };
	vector<int> edgeb = { bd[0].valb };
	for (int i = 0; i < bd.size(); i++) {
		// これまで壊した橋の領域では足りない場合
		if (edgeb.back() <= bd[i].vala) {
			// 新しい範囲を追加
			edgea.push_back(bd[i].vala);
			edgeb.push_back(bd[i].valb);
		}
		// これまで壊した橋の領域を延ばせばいい場合
		else {
			if (edgeb.back() > bd[i].valb) {
				// 範囲の右端を与える b の値を更新
				edgeb[edgeb.size() - 1] = bd[i].valb;
			}
			if (edgea.back() < bd[i].vala) {
				// 範囲の右端を与える b の値を更新
				edgea[edgea.size() - 1] = bd[i].vala;
			}
		}
	}

	int ans = edgea.size();

	cout << ans << endl;

	return 0;
}
