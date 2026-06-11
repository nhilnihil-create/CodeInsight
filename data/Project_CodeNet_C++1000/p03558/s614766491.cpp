#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <functional>

using namespace std;
using ll = long long;

#define FOR(i, m, n) for(int i = (m);i < (n);i++)
#define REP(i,n) for(int i = 0; i < int(n); i++)
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VL vector<ll>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define PAIR pair<int,int>
#define MP make_pair
#define VP vector<pair<int,int>>
#define VS vector<string>
#define QUE queue<int>
#define DEQ deque<int>
#define PQUE priority_queue<int> //5,5,4,3,3,2,...
#define REPQUE priority_queue<int, vector<int>, greater<int>> //1,1,2,3,4,4,5,...
#define SUM(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SORT(obj) ((obj).begin(), (obj).end()) // 1,2,3,4,5...
#define RESORT(obj) ((obj).begin(), (obj).end(), greater<int>()) // 5,4,3,2,1...
#define UB(obj,n) upper_bound((obj).begin(), (obj).end(), n) //itr > n
#define LB(obj,n) lower_bound((obj).begin(), (obj).end(), n) //itr>= n

const ll MOD = (ll)1e9 + 7;

int bfs(int K);

int main() {
	int K;
	cin >> K;
	cout << bfs(K) << endl;
	return 0;
}

int bfs(int K) {
	VB node(K, true);
	deque<PAIR> que;
	que.push_back(PAIR(1, 1));

	while (!que.empty()) {
		int score = que.front().first;
		int position = que.front().second;
		int next_position;
		que.pop_front();
		if (position == 0) return score;

		node[position] = false;

		next_position = (position * 10) % K;
		if (node[next_position]) que.push_front(PAIR(score, next_position));

		next_position = (position + 1) % K;
		if (node[next_position]) que.push_back(PAIR(score + 1, next_position));
		
	}
}

