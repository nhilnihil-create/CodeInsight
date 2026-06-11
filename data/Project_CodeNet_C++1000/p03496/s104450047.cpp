#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	int N; 
  	cin >> N; 
	int A[60] = {}; 
	for(int i = 0; i < N; i++){
		cin >> A[i]; 
	}
	int absmax = 0; 
	for(int i = 0; i < N; i++){
		if(abs(A[i]) > abs(A[absmax])){
			absmax = i; 
		}
	}
	cout << N * 2 - 1 << endl; 
	for(int i = 0; i < N; i++){
		cout << absmax + 1 << " " << i+1 << endl; 
	}
	if(A[absmax] >= 0){
		for(int i = 0; i < N-1; i++){
			cout << i+1 << " " << i + 2 << endl; 
		}
	}
	if(A[absmax] < 0){
		for(int i = N-2; i >= 0; i--){
			cout << i+2 << " " << i+1 << endl; 
		}
	}
}