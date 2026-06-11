#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<vector<int>> E(N);
	for (int i = 0; i < N - 1; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	vector<int> c(N);
	for (int i = 0; i < N; i++){
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());
	vector<int> d(N, 0);
	d[0] = c[0];
	int ans = 0;
	int cnt = 1;
	queue<int> Q;
	Q.push(0);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int w : E[v]){
			if (d[w] == 0){
				d[w] = c[cnt];
				ans += d[w];
				cnt++;
				Q.push(w);
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < N; i++){
		cout << d[i];
		if (i < N - 1){
			cout << ' ';
		}
	}
	cout << endl;
}