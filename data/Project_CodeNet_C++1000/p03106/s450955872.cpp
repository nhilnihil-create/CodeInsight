#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int calc(int N,int K) {
	vector<int> x;
	for (int i = 1; i <= sqrt(N); i++) {
		if (0 == N % i) {
			x.push_back(i);
			if (N != i * i) {
				x.push_back(N / i);
			}
		}
	}
	sort(x.begin(),x.end());
	return x[x.size()-K];
}


int main() {
	int A, B, K;
	cin >> A >> B >> K;
	int g = gcd(A, B);
	int ans = calc(g, K);
	cout << ans << endl;

}