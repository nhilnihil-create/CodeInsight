#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);



int main() {
	int N, K; cin >> N >> K;
	vector<int> V;
	rep(i, N) {
		int v; cin >> v;
		V.push_back(v);
	}
	
	long long ans = 0;
	rep(i, N + 1) {
		rep(j, N - i + 1) {
			if (K >= i + j) {
				rep(k, K - i - j + 1) {
					if (i + j + k != 0) {
						//cout << i << " " << j << " " << k << endl;
						priority_queue<int, vector<int>, greater<int>> pq;
						rep(l, i)pq.push(V[V.size() - l - 1]);
						rep(l, j)pq.push(V[l]);
						int count = 0;
						/*cout << "num" << endl;
						cout << pq.size() << endl;
						cout << count << endl;*/
						while (!pq.empty() && count != k) {
							pq.pop();
							//cout << "pop" << endl;
							++count;
						}
						/*cout << "num" << endl;*/
						long long num = 0;
						while (!pq.empty()) {
							num += (long long)pq.top();
							pq.pop();
						}
						if (ans < num)ans = num;
						/*cout << num << endl;*/
					}
				}
			}
		}
	}
	cout << ans;

}