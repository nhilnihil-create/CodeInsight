#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, absmax = 0;
	cin >> N;
	cout << 2*N-1 << endl;
	int A[N];
	for(int i=0; i<N; i++){
		cin >> A[i];
		if(abs(A[absmax]) < abs(A[i])) absmax = i;
	}
	for(int i=0; i<N; i++) cout << absmax + 1 << " " << i + 1 << endl;
	if(A[absmax] < 0){
		for(int i=N; i>1; i--) cout << i << " " << i - 1 << endl;
	}else{
		for(int i=0; i<N-1; i++) cout << i + 1 << " " << i + 2 << endl;
	}
	return 0;
}