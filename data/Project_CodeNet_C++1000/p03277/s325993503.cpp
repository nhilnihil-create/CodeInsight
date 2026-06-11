#include <bits/stdc++.h>
using namespace std;
int N, A[100010], C[100010], S[100010], bit[200010]; 
void add(int a, int b){
	int x = a; 
	while(x <= N*2+1){
		bit[x] += b; x += x & -x; 
	}
}
int sum(int a){
	int res = 0; 
	int x = a; 
	while(x > 0){
		res += bit[x]; x -= x & -x;
	}
	return res; 
}
bool solve(int M){
	long long int cor = 0; 
	fill(bit, bit+2*N+2, 0); // -N～Nがそれぞれbit[1]～bit[2N+1]に対応
	add(N+1, 1); 
	for(int i = 1; i <= N; i++){
		if(A[i] >= M) C[i] = 1; 
		else C[i] = -1; 
		S[i] = S[i-1] + C[i]; 
		cor += (long long) sum(S[i] + N + 1); 
		add(S[i] + N + 1, 1);
	}
	return (cor * 2 >= (long long) N * (N+1) / 2); 
}
int main(){
	cin >> N; 
	for(int i = 1; i <= N; i++){
		cin >> A[i]; 
	}
	int ng = 1e9+7; int ok = 0; 
	while(ng - ok > 1){
		int mid = (ok + ng) / 2; 
		if(solve(mid)) ok = mid; 
		else ng = mid; 
	}
	cout << ok << endl; 
}