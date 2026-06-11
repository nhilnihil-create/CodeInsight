#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<long long> PPP(N), PPM(N), PMP(N), PMM(N);
	for (int i = 0; i < N; i++) {
		long long x, y, z;
		cin >> x >> y >> z;
		PPP[i] = x + y + z;
		PPM[i] = x + y - z;
		PMP[i] = x - y + z;
		PMM[i] = x - y - z;
	}
	sort(PPP.begin(), PPP.end());
	sort(PPM.begin(), PPM.end());
	sort(PMP.begin(), PMP.end());
	sort(PMM.begin(), PMM.end());
	vector<long long> sum(8);
	for (int i = 0; i < M; i++) {
		sum[0] -= PPP[i];
		sum[1] -= PPM[i];
		sum[2] -= PMP[i];
		sum[3] -= PMM[i];
		sum[4] += PPP[N - 1 - i];
		sum[5] += PPM[N - 1 - i];
		sum[6] += PMP[N - 1 - i];
		sum[7] += PMM[N - 1 - i];
	}
	cout << *max_element(sum.begin(), sum.end()) << endl;
}