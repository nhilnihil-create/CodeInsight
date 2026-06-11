#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	long long D, N;
	cin >> D >> N;

	if (N == 100) N++;
	cout << fixed << setprecision(0);
	cout << N * pow(100, D) << endl;
}