#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, A, B; 
	cin >> N >> A >> B; 
	if((long long) N > (long long) A * B){
		cout << -1 << endl; return 0; 
	}
	if(N < A + B - 1){
		cout << -1 << endl; return 0; 
	}
	int num[300010] = {}; 
	int start[300010] = {}; 
	num[0] = A; int tmp = N - B - A + 1; 
	for(int i = 1; i < B; i++){
		num[i] ++; 
		num[i] += min(A-1, tmp); 
		tmp -= min(A-1, tmp); 
	}
	start[B-1] = 1; 
	for(int i = B-2; i >= 0; i--){
		start[i] = start[i+1] + num[i+1]; 
	}
	for(int i = 0; i < B; i++){
		for(int j = 0; j < num[i]; j++){
			cout << start[i] + j << " "; 
		}
	}
	cout << endl; 
}