#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//see answer
int main() {
	int N, K;
	cin >> N >> K;
	vector<long long> X(N), Y(N);
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	long long ans = 5 * powl(10, 18);
	for (int p1 = 0; p1 < N; p1++) {
		for (int p2 = 0; p2 < N; p2++) {
			for (int p3 = 0; p3 < N; p3++) {
				for (int p4 = 0; p4 < N; p4++) {
					long long xl = min({ X[p1],X[p2],X[p3],X[p4] });
					long long xr = max({ X[p1],X[p2],X[p3],X[p4] });
					long long yu = min({ Y[p1],Y[p2],Y[p3],Y[p4] });
					long long yd = max({ Y[p1],Y[p2],Y[p3],Y[p4] });
					int num = 0;
					for (int i = 0; i < N; i++) num += (X[i] >= xl && X[i] <= xr && Y[i] >= yu && Y[i] <= yd);
					if (num >= K) ans = min(ans, (xr - xl) * (yd - yu));
				}
			}
		}
	}
	cout << ans << endl;
}
