#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int	main()
{
	int	N, M;
	int	A, B;
	cin >> N >> M;
	Graph		graph(N);
	vector<int>	dg(N, 0);
	for (int i = 0; i < M; ++i) {
		cin >> A >> B;
		--A; --B;
		graph.at(A).push_back(B);
		graph.at(B).push_back(A);
		++dg.at(A);
		++dg.at(B);
	}
	queue<int>		que;
	vector<int>		color(N, -1);
	color.at(0) = 0;
	que.push(0);
	bool	is_bipartile = true;
	while (!que.empty()) {
		int	u = que.front(); que.pop();	
		for (int v : graph.at(u)) {
			if (color.at(v) >= 0) {
				if (color.at(v) == color.at(u)) {
					is_bipartile = false;
					break;
				}
				continue;	
			}
			color.at(v) = (color.at(u) + 1) % 2;
			que.push(v);
		}
	}
	int64_t	cnt = 0;
	if (!is_bipartile) {
		cnt = N;
		cnt = cnt * (N - 1) / 2 - M;
		cout << cnt << endl;
		return 0;
	}
	int	cnt_0 = 0, cnt_1 = 0;
	for (int i = 0; i < N; ++i) {
		if (color.at(i) == 0) 
			++cnt_0;
		else
			++cnt_1;
	}
	for (int i = 0; i < N; ++i) {
		if (color.at(i) == 0)
			cnt += cnt_1 - dg.at(i);
		else
			cnt += cnt_0 - dg.at(i);
	}
	cout << cnt / 2 << endl;
	return 0;
}	
