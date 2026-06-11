#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int64_t A, B;
	int K;
	cin >> A >> B >> K;

	rep(i, K){
		if (A + i > B) return 0;
		cout << A + i << endl;
	}
	for(int i = K - 1; i >= 0; i--){
		if (B - i < A + K) continue;
		cout << B - i << endl;
	}
}