#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	vector<int>A(M);
	int x = 0;
	int y = 0;
	for (int i = 0;i<M;++i) {
		cin >> A[i];
		if(X<A[i]){
			x++;
		}
		else {
			y++;
		}
	}
	cout << min(x,y) << endl;
}
