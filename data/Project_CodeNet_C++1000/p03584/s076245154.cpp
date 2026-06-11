#include <bits/stdc++.h>
using namespace std; 
int main(){
	int N, K; cin >> N >> K; 
	int A[100010] = {}; long long int B[100010] = {}; 
	for(int i = 0; i < N; i++){
		cin >> A[i] >> B[i]; 
	}
	long long int ans[35] = {}; // 下位ibit目で初めてK+1未満が確定
	for(int i = 0; i < 31; i++){
		if(!(((K+1) >> i) & 1)) continue; 
		int L = ((K+1) >> i) - 1; 
		for(int j = 0; j < N; j++){
			int c = (A[j] >> i); 
			bool ok = true; 
			for(int k = 0; k < 32 - i; k++){
				if(!((L >> k) & 1) && ((c >> k) & 1)) ok = false; 
			}
			if(ok) ans[i] += B[j]; 
		}
	}
	long long int mx = 0; 
	for(int i = 0; i < 31; i++){
		mx = max(mx, ans[i]); 
	}
	cout << mx << endl; 
}