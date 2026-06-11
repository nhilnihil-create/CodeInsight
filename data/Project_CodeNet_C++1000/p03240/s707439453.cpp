#include <bits/stdc++.h>
using namespace std;

int N;
int X[110], Y[110], H[110];

int main(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> X[i] >> Y[i] >> H[i];
	}
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++){
			int H_ = 0;
			for (int k = 1; k <= N; k++)
				if (H[k] > 0){
					H_ = H[k] + abs(i - X[k]) + abs(j - Y[k]);
					break;
				}
			for (int k = 1; k <= N; k++)
				if (max(H_ - abs(i - X[k]) - abs(j - Y[k]), 0) != H[k]){
					H_ = 0;
					break;
				}
			if (H_ == 0)
				continue;
			cout << i << ' ' << j << ' ' << H_ << endl;
		}
}