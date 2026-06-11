#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	if(N % 2 == 0) {
		cout << N * (N - 1) / 2 - N / 2 << endl;
		for(int i=1;i<=N;i++) {
			int forbidden = N - (i - 1);
			for(int j=i+1;j<=N;j++) {
				if(j == forbidden) continue;
				cout << i << " " << j << endl;
			}
		}
	} else {
		cout << N * (N - 1) / 2 - (N - 1) / 2 << endl;
		for(int i=1;i<=N;i++) {
			int forbidden = N - i;
			for(int j=i+1;j<=N;j++) {
				if(j == forbidden) continue;
				cout << i << " " << j << endl;
			}
		}
	}
}