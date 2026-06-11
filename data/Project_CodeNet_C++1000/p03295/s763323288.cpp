#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
#include <cstring>
typedef long long ll;
typedef long double ld;


#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;

/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int MAX_A = 100000;
const int MAX_B = 0;
ll H, W;
ll sX, sY, gX, gY;
ll N, M;
vector<int> graph;
ll X[MAX_A];
ll L[MAX_A];
P ps[MAX_A];

int vector_finder(std::vector<int> vec, int number) {
	auto itr = std::find(vec.begin(), vec.end(), number);
	size_t index = std::distance(vec.begin(), itr);
	if (index != vec.size()) { // 発見できたとき
		return 1;
	}
	else { // 発見できなかったとき
		return 0;
	}
}
int main() {
	cin >> N >> M;
	Graph armWidth = Graph(N,vector<ll>(2));
	rep(i,M) {
		cin >> X[i] >> L[i];
		ps[i] = P(L[i],X[i]);
	}
	sort(ps, ps + M);
	int cur = -MAX_B;
	int ans = 0;
	rep(i,M) {
		if (cur<=ps[i].second) {
			ans++;
			cur = ps[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}