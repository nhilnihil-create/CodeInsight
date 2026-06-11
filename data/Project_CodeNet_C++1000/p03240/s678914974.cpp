#include "bits/stdc++.h"
using namespace std;

int main() {
	int N ;
	cin >> N;
	vector<int>X(N);
	vector<int>Y(N);
	vector<int>H(N);
	int i;
	for (int n = 0;n<N;++n) {
		cin >> X[n] >> Y[n] >> H[n];
		if (H[n] > 0) {
			i = n;
		}
	}
	for (int x = 0;x<=100;++x) {
		for (int y = 0;y<=100;++y) {
			bool next = true;
			int High = H[i] + abs(X[i] - x) + abs(Y[i] - y);
			for (int n = 0;n<N;++n) {
				if ((H[n]>0)&&(High != H[n] + abs(X[n] - x) + abs(Y[n] - y))) {
					next = false;
					break;
				}
				if ((H[n]==0)&&((High > abs(X[n] - x) + abs(Y[n] - y)))) {
					next = false;
					break;
				}
			}
			if(next){
				cout << x<<" "<<y<<" "<<High<<endl;
			}
		}
	}
	return 0;
}