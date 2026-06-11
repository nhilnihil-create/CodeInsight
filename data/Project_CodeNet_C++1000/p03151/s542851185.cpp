#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int N; cin >> N;
	long long a = 0;
	vector<long long>A(N),B(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		cin >> B[i];A[i] -= B[i];
	}
	sort(A.begin(), A.end());
	int ans = 0;
	for(int i=0;i<N;i++){
		if (A[i] < 0) {
			a += A[i]; ans++;
			A[i] = 0;
		}
	}
	for (int i = N-1; i >= 0; i--) {
		if (a >= 0)break;
		a += A[i]; ans++;
	}
	if (a>=0)cout << ans << endl;
	else cout << -1 << endl;
}



