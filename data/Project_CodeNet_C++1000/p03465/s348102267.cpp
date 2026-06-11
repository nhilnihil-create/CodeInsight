#include <bits/stdc++.h>
#include <bitset>
using namespace std;
int main(){
	int N, A[2010]; 
	cin >> N;
	int S = 0; 
	for(int i = 0; i < N; i++){
		cin >> A[i]; S += A[i]; 
	}
	bitset<4000010> B; 
	B.reset();
	B.set(0, 1); 
	for(int i = 0; i < N; i++){
		B |= (B << A[i]); 
	}
	for(int i = (S+1)/2; i <= S; i++){
		if(B.test(i)){
			cout << i << endl; return 0; 
		}
	}
}