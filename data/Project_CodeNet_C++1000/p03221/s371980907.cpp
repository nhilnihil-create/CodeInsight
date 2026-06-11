#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector< vector< pair<int, int> > > ord(N);	//y, id
	for (int ii = 0; ii < M; ++ii){
		int p, y;
		cin >> p >> y;
		p--;
		ord[p].push_back(make_pair(y, ii));
	}

	for (int ii = 0; ii < N; ++ii){
		sort(ord[ii].begin(), ord[ii].end());
	}

	vector < pair<int, int> > ID(M);
	for (int ken = 0; ken < N; ++ken){
		for (int id = 0; id < ord[ken].size(); ++id){
			int idx = ord[ken][id].second;
			ID[idx] = make_pair(ken, id);
		}
	}

	for (int ii = 0; ii < M; ++ii){
		int ken = ID[ii].first + 1;
		int id = ID[ii].second + 1;
		printf("%06i%06i\n", ken, id);
	}

	return 0;
}
