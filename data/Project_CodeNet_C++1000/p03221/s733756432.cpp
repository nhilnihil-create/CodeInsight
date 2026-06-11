#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
typedef long long ll;
using namespace std;
#define INF (1 << 30)
#define INFLL (1LL << 60)
#define rep(i, n) for(int i=0; i<(n); ++i)

int main()
{
	int N, M; cin >> N >> M;
	vector<int> P(M), Y(M);
	for (int i = 0; i < M; ++i) cin >> P[i] >> Y[i], --P[i];

	//同じ県の市をまとめる
	vector<vector<int> > vals(N);
	for (int i = 0; i < M; ++i) vals[P[i]].push_back(Y[i]);

	//各県の市の順番を並べ替える
	for (int p = 0; p < N; ++p) {
		sort(vals[p].begin(), vals[p].end());
		//vals[p].erase(unique(vals[p].begin(), vals[p].end()), vals[p].end());	//重複する値は削除する
	}

	for (int i = 0; i < M; ++i) {
		int p = P[i];
		printf("%06d", p + 1);

		//Y[i]年が何番目かを求める
		int id = lower_bound(vals[p].begin(), vals[p].end(), Y[i]) - vals[p].begin();

		printf("%06d\n", id + 1);
	}
	//rep(i, M) {
	//	cout << setw(6) << setfill('0');
	//	cout << setw(6) << setfill('0');
	//	cout << endl;
	//}
	return 0;
}
