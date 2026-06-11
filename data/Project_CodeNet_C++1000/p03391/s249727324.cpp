#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N], B[N];
	long long sum = 0;
	int M = 1e9+1, f = 0;
	for(int i=0; i<N; i++) cin >> A[i] >> B[i];
	for(int i=0; i<N; i++){
		sum += A[i];
		if(A[i] > B[i]){
			M = min(B[i], M);
		}
		if(A[i] != B[i]) f = 1;
	}
	if(f){
		cout << sum - M << endl;
	}else{
		cout << 0 << endl;
	}
	return 0;
}
