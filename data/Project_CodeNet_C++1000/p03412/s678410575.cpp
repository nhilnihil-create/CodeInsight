#include<bits/stdc++.h>
using namespace std;

long long N;
long long A[200005];
long long B[200005];


int main(){
	cin >> N;
	for(long long i = 0; i < N; i++){
		cin >> A[i];
	}
	for(long long i = 0; i < N; i++){
		cin >> B[i];
	}

	long long ans = 0;
	for(long long bit = 0; bit <= 28; bit++){
		long long MOD = (1<<(bit + 1));
		vector<long long> modB;
		for(long long i = 0; i < N; i++){
			modB.push_back(B[i]%MOD);
		}
		sort(modB.begin(), modB.end());

		long long num = 0;
		for(long long i = 0; i < N; i++){
			long long a = lower_bound(modB.begin(), modB.end(), (1 * (1<<bit) - A[i]%MOD)) - modB.begin();
			long long b = lower_bound(modB.begin(), modB.end(), (2 * (1<<bit) - A[i]%MOD)) - modB.begin();
			long long c = lower_bound(modB.begin(), modB.end(), (3 * (1<<bit) - A[i]%MOD)) - modB.begin();
			long long d = lower_bound(modB.begin(), modB.end(), (4 * (1<<bit) - A[i]%MOD)) - modB.begin();
			//if(modB[b] == 2 * (1<<bit) - A[i]%MOD)
			//	b--;
			//if(modB[d] == 4 * (1<<bit) - A[i]%MOD)
			//	d--;
			num += (b - a) + (d - c);
		}
		if(num%2 == 1){
			ans += (1<<bit);
		}
	}
	cout << ans << endl;
}