#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; 
	cin >> N; 
	long long int A[200010] = {}; 
	for(int i = 0; i < N; i++) cin >> A[i]; 
	if(A[0] != 0){
		cout << -1 << endl; return 0; 
	} 
	for(int i = 0; i < N-1; i++){
		if(A[i] + 1 < A[i+1]){
			cout << -1 << endl; return 0; 
		}
	}
	long long int ans = 0; 
	for(int i = 0; i < N; i++){
		if(A[i] >= A[i+1]){
			ans += A[i]; 
		}
	}
	cout << ans << endl; 
}