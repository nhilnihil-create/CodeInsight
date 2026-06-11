#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		vector<long long> L(N), R(N);
		for(int i=0;i<N;i++) cin >> L[i] >> R[i];
		sort(L.rbegin(), L.rend());
		sort(R.begin(), R.end());
		vector<long long> sumL(N+1, 0);
		vector<long long> sumR(N+1, 0);
		for(int i=0;i<N;i++){
			sumL[i+1] = sumL[i] + 2 * L[i];
			sumR[i+1] = sumR[i] - 2 * R[i];
		}
		long long res = 0;
		for(int i=0;i<=N;i++){
			res = max(res, sumL[i] + sumR[i]);
			if(i+1 <= N){
				res = max(res, sumL[i] + sumR[i+1]);
				res = max(res, sumL[i+1] + sumR[i]);
			}
		}
		cout << res << endl;
	}
}
