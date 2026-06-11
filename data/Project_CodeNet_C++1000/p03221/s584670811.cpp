#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	pair<int, int> id[M];
	vector<pair<int, int> > comprise[N];
	for (int i = 0; i < M; ++i){
		int prefecture, birth;
		scanf("%d %d", &prefecture, &birth);
		id[i].first = prefecture;
		prefecture--;
		comprise[prefecture].push_back(make_pair(birth, i));
	}
	for (int i = 0; i < N; ++i){
		sort(comprise[i].begin(), comprise[i].end());
		for (int j = 0; j < comprise[i].size(); ++j){
			id[comprise[i][j].second].second = j + 1;
		}
	}
	for (int i = 0; i < M; ++i){
		printf("%06d%06d\n", id[i].first, id[i].second);
	}
	return 0;
}