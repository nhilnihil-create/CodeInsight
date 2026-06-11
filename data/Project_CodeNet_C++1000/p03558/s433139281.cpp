#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
const int MAX = 1e5;
const int INF = 1e8;
int K;
int d[MAX];

int bfs() {
	deque<int> deq;
		rep(i, K) d[i] = INF;
	deq.push_front(1);
	d[1] = 1;

		while (true) {
			int p = deq.front();
			deq.pop_front();

			if (p == 0)break;

			int pt = (10 * p) % K;
			if (d[pt] >d[p]) {
				deq.push_front(pt);
				d[pt] = d[p];
			}

			int pp = (p + 1) % K;
			if (d[pp] >d[p]+1) {
				deq.push_back(pp);
				d[pp] = d[p] + 1;
			}
		}
	return d[0];
}

int main() {
	cin >> K;

	int res = bfs();
	cout << res;
}