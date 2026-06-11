#include<bits/stdc++.h>
using namespace std;

long long N, K;
long long A[100005];
long long B[100005];


long long cal(long long limi, long long len){
	//cout << limi << ", " << len << endl;
	long long ret = 0;
	for(long long i = 0; i < N; i++){
		bool ok = true;
		if((len > 0) && (A[i]>>(len - 1))&1){
			ok = false;
		}

		for(long long j = len; j < 32; j++){
			if((((limi >> j)&1) == 0) && (((A[i] >> j)&1) == 1)){
				ok = false;
			}
		}
		if(ok){
			//cout << "ok " << A[i] << endl;
			ret += B[i];
		}
	}
	return ret;
}



int main(){
	cin >> N >> K;

	for(long long i = 0; i < N; i++)
		cin >> A[i] >> B[i];

	long long maxi = 0;
	for(long long i = 0; i < 32; i++){
		if(i == 0 || (K>>(i-1))&1){
			long long tmp = cal((K>>i) << i, i);
			maxi = max(maxi, tmp);
		}
	}
	cout << maxi << endl;
}
