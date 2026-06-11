#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	int N; 
	cin >> N; 
	int T[110] = {}; 
	int V[110] = {}; 
	int S[110] = {}; 
	for(int i = 1; i <= N; i++){
		cin >> T[i];
		S[i] = S[i-1] + T[i] * 2; 
	}
	for(int i = 1; i <= N; i++){
		cin >> V[i]; 
	}
	int A[40010] = {}; // N+1個の関数の最小値を各点について考える．0.5の整数倍で切り替わることがあるので，あらかじめVもTも2倍しておいて，あとで積分値を4で割る．
	for(int t = 0; t <= S[N]; t++){
		A[t] = min(t, S[N] - t); 
	}
	for(int i = 1; i <= N; i++){
		for(int t = 0; t <= S[N]; t++){
			if(t < S[i-1]){A[t] = min(A[t], V[i] * 2 - t + S[i-1]);}
			else if(t >= S[i-1] && t <= S[i]){A[t] = min(A[t], V[i] * 2);}		
			else if(t > S[i]){A[t] = min(A[t], V[i] * 2 + t - S[i]);}
		}
	}
	int ans = 0; 
	for(int i = 1; i < S[N]; i++){
		ans += A[i]; 
	}
	cout.precision(10); 
	cout << (double) ans * 0.25 << endl; 
}