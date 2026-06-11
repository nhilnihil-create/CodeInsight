#include<bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
int N, M, Q,L,R;
vector<vector<int>> p(510, vector<int>(510, 0));
int main() {
	cin >> N >> M >> Q;
	rep(i, M) { cin >> L >> R; p[L][R]++; }
	req(i, N) req(j, N) p[i][j] += p[i - 1][j];
	req(i, N) req(j, N) p[i][j] += p[i][j- 1];
	rep(i, Q) {
		cin >> L >> R;
		cout << p[R][R] + p[L - 1][L - 1] - p[L - 1][R] - p[R][L - 1] << endl;
	}
}
