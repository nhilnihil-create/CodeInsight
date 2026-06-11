#include <bits/stdc++.h>
#define ALL(a) (a).begin(),(a).end()
#define N_MAX 1000
#define ll long long int
using namespace std;

int dig(int N) {//桁数
	int dig = 0;
	while (N) {
		dig++;
		N /= 10;
	}
	return dig;
}

int main() {
	int N, K; cin >> N >> K;
	cout << N - K + 1 << endl;
}
