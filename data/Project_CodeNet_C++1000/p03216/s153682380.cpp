#include <bits/stdc++.h>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	int N, Q; string S; 
	cin >> N >> S >> Q; 
	int D[1000010] = {}; 
	int M[1000010] = {}; 
	int C[1000010] = {}; 
	for(int i = 1; i <= N; i++){
		if(S[i-1] == 'D') D[i] = D[i-1] + 1; 
		else D[i] = D[i-1]; 
		if(S[i-1] == 'M') M[i] = M[i-1] + 1; 
		else M[i] = M[i-1]; 
		if(S[i-1] == 'C') C[i] = C[i-1] + 1; 
		else C[i] = C[i-1]; 
	}
	for(int q = 0; q < Q; q++){
		int K; cin >> K; 
		long long ans = 0; 
		for(int i = 0; i < N; i++){
			if(S.at(i) == 'D'){
				ans -= (long long) M[i+1] * (C[min(i+K, N)] - C[i]); 
			}
			if(S.at(i) == 'C'){
				ans += (long long) M[i+1] * (D[i+1] - D[max(i+1-K, 0)]); 
			}			
		}
		cout << ans << endl; 
	}
}