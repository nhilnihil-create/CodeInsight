#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<queue>
#include<cassert>
#include<tuple>
#include<set>
#include<map>
#include<list>
#include<bitset>

#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)

#define mod 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int INF = (int)1e9;

int d[100010];

int main() {
	int k;
	cin >> k;
	rep(i, k) d[i] = INF;
	d[k] = 0; //kから始める

	deque<int> dq;
	dq.push_front(k);
	while (!dq.empty()) {
		int u = dq.front(); //前から出す
		dq.pop_front();
		int n0 = (u == k) ? k : (u * 10) % k; //uがkでなければ×10してmodk
		int n1 = (u + 1) % k; //uに１を足してmodk
		if (d[n0] > d[u]) { //×10した最短路
			d[n0] = d[u];
			dq.push_front(n0); //前に入れる
		}
		if (d[n1] > d[u] + 1) { //+1した最短路
			d[n1] = d[u] + 1;
			dq.push_back(n1); //後ろに入れる
		}
	}
	cout << d[0] << endl;
	return 0;
}