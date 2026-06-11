#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(long long i=0;i<x;i++)

int main(){	
	long long K;
	long long M;
	scanf("%lld",&M);
	scanf("%lld",&K);
	if (1<<M <= K || (M == 1 && K == 1)) {
		cout << "-1" << endl;
		return 0;
	}
	if (M == 1 && K == 0) {
		{
			cout << "1 1 0 0" << endl;
			return 0;
		}
	}
	rep(i, 1<<M) {
		if (i == K) continue;
		cout << i << " ";
	}
	cout << K << " ";
	rep(i, 1<<M) {
		if ((1<<M)-1-i == K) continue;
		cout << (1<<M)-1-i << " ";
	}
	cout << K << endl;

	return 0;
}

