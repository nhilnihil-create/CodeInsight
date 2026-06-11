#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W;
	cin >> H >> W; 
	vector<vector<int>> A(H, vector<int>(W));
	for (int h = 0;h<H;++h) {
		for (int w = 0;w<W;++w) {
			cin >> A[h][w];
		}
	}
	vector<vector<int>> Ans;
	int memo = 1;
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			if (1 == memo) {
				if (1 == A[h][w] % 2) {
					if (w != W-1) {
						A[h][w]--;
						A[h][w+1]++; 
						vector<int> vec = { h + 1,w + 1,h + 1,w + 2 };
						Ans.push_back(vec);
					}
					else {
						if (h != H - 1) {
							A[h][w]--;
							A[h + 1][w]++;
							vector<int> vec = { h + 1,w + 1,h + 2,w + 1 };
							Ans.push_back(vec);
						}
					}
				}
			}
			else {
				if (1 == A[h][W-1-w] % 2) {
					if (w != W - 1) {
						A[h][W - 1 - w]--;
						A[h][W - 2 - w]++;
						vector<int> vec = { h + 1,W - w,h + 1,W - 1 - w };
						Ans.push_back(vec);
					}
					else {
						if (h != H - 1) {
							A[h][W - 1 - w]--;
							A[h + 1][W - 1 - w]++;
							vector<int> vec = { h + 1,W - w,h + 2,W - w };
							Ans.push_back(vec);
						}
					}
				}
			}

		}
		memo *= -1;
	}
	cout << Ans.size()<<endl;
	for (int n = 0;n<Ans.size();++n) {
		cout << Ans[n][0]<<" " << Ans[n][1] << " " << Ans[n][2] << " " << Ans[n][3] <<endl;
	}
	return 0;
}