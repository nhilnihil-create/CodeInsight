#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> vec;
	/*
	vector<int> vec1
	vec.push_back();

	vector<vector<int>> vec2;
	vec[0].push_back();

	sort(vec[0].begin(), vec[0].end());

	vectorの形 
	N行0列の2次元vector
			0	1	2	3
	vec[0] 
	1 <- こいつの要素はvector<int>で宣言されている
	2
	3
	4
	.
	.
	.
	.
	.
	N-1
	*/


	vector<vector<int>> vec2(N + 1);

	for (int i = 0; i < M; ++i) {//入れる処理
		int p, y;
		cin >> p >> y;
		vec.push_back(make_pair(p, y));
		vec2[p].push_back(y);
	}

	map<pair<int, int>, int> mp;
	for (int i = 1; i <= N; ++i) {
		sort(vec2[i].begin(), vec2[i].end());//vec[i]の要素をソート
		/*
		p:県の番号
		y:その県の中にある市の誕生年
		p	y
		1	55	91	42	45	12	01	49	73	71
		2	81	84	12	47	472	374
				*/
		int number = 1;
		for (int j = 0; j < vec2[i].size(); ++j) {
			mp[make_pair(i, vec2[i][j])] = number++;
 		}
	}

	for (int i = 0; i < vec.size(); ++i) {
		printf("%06d%06d\n", vec[i].first, mp[vec[i]]);
	}
	return 0;
}