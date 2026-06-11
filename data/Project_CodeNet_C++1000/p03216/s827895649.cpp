#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	string S;
	cin >> S;
	int Q;
	cin >> Q;
	int k[Q];
	long long int D[N], M[N];
	for(int i=0; i<N; i++){	
		if(i == 0){
			if(S[i] == 'D'){
				D[0] = 1;
			}else{
				D[0] = 0;
			}
			if(S[i] == 'M'){
				M[0] = 1;
			}else{
				M[0] = 0;
			}
		}else{
			if(S[i] == 'D'){
				D[i] = D[i-1] + 1;
			}else{
				D[i] = D[i-1];
			}
			if(S[i] == 'M'){
				M[i] = M[i-1] + 1;
			}else{
				M[i] = M[i-1];
			}
		}
	}
	for(int i=0; i<Q; i++){
		cin >> k[i];
	}
	for(int x=0; x<Q; x++){
		long long int dmc[N], dm[N];
		dm[0] = 0, dmc[0] = 0;
		for(int i=1; i<N; i++){
			if(i+1 < k[x]){
				if(S[i] == 'M'){
					dm[i] = dm[i-1] + D[i-1];
				}else{
					dm[i] = dm[i-1];
				}
			}else{
				if(S[i-k[x]+1] == 'D' && S[i] == 'M'){
					dm[i] = dm[i-1] - M[i-1] + M[i-k[x]+1] + D[i-1] - D[i-k[x]+1];
				}else if(S[i-k[x]+1] == 'D'){
					dm[i] = dm[i-1] - M[i-1] + M[i-k[x]+1];
				}else if(S[i] == 'M'){
					dm[i] = dm[i-1] + D[i-1] - D[i-k[x]+1];
				}else{
					dm[i] = dm[i-1];
				}
			}
			if(S[i] == 'C'){
				dmc[i] = dmc[i-1] + dm[i-1];
			}else{
				dmc[i] = dmc[i-1];
			}
		}
		cout << dmc[N-1] << endl;
	}
	return 0;
}