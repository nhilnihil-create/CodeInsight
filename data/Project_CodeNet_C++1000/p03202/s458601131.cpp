#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; 
	int A[200010]; 
	cin >> N; 
	for(int i = 0; i < N; i++) cin >> A[i]; 
	int C[200010] = {}; // 文字
	int L[200010] = {}; // 長さ
	int ok = N; int ng = 0; 
	while(ok - ng > 1){
		C[0] = 0; L[0] = A[0]; 
		bool possible = true; 
		int mid = (ok + ng) / 2; 
		int it = 0; 
		for(int i = 1; i < N; i++){
			if(A[i] > A[i-1]){
				if(C[it] == 0) L[it] += A[i] - A[i-1]; 
				else{
					it++; C[it] = 0; L[it] = A[i] - A[i-1]; 
				}
			}
			else if(A[i] == A[i-1]){
				if(L[it] == 1) C[it] ++; 
				else{
					L[it]--; it++; L[it] = 1; C[it] = C[it-1] + 1; 
				} 
				if(C[it] >= mid){
					int del = 0; 
					while(C[it] >= mid - 1){
						del += L[it]; it--; 
						if(it < 0){
							possible = false; break; 
						}
					}
					if(L[it] == 1){
						C[it]++; it++; L[it] = del; C[it] = 0; 
					}
					else{
						L[it]--; it++; C[it] = C[it-1] + 1; 
						L[it] = 1; it++; C[it] = 0; L[it] = del; 
					}
				}
			}
			else if(A[i] < A[i-1]){
				int dec = A[i-1] - A[i]; 
				while(it >= 0 && dec >= 0){
					dec -= L[it]; it--; 
				}
				it++; dec += L[it]; 
				if(dec + 1 == L[it]){
					C[it] ++; L[it] = 1;  
				}
				else{
					L[it] -= dec + 1; it++; 
					L[it] = 1; C[it] = C[it-1] + 1;
				}
				if(C[it] >= mid){
					int del = 0; 
					while(C[it] >= mid - 1){
						del += L[it]; it--; 
						if(it < 0){
							possible = false; break; 
						}
					}
					if(L[it] == 1){
						C[it]++; it++; L[it] = del; C[it] = 0; 
					}
					else{
						L[it]--; it++; C[it] = C[it-1] + 1; 
						L[it] = 1; it++; C[it] = 0; L[it] = del; 
					}
				}
			}
		}
		if(possible) ok = mid; 
		else ng = mid; 
	}
	cout << ok << endl; 
}