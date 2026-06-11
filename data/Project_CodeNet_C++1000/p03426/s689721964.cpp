#include <iostream>
#include <vector>
using namespace std;
int main(){
	int H, W, D;
	cin >> H >> W >> D;
	vector<vector<int>> A(H, vector<int>(W));
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			cin >> A[i][j];
			A[i][j]--;
		}
	}
	int N = H * W;
	vector<int> y(N), x(N);
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			y[A[i][j]] = i;
			x[A[i][j]] = j;
		}
	}
	vector<int> S(N, 0);
	for (int i = D; i < N; i++){
		S[i] = S[i - D] + abs(y[i] - y[i - D]) + abs(x[i] - x[i - D]);
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++){
		int L, R;
		cin >> L >> R;
		L--;
		R--;
		cout << S[R] - S[L] << endl;
	}
}