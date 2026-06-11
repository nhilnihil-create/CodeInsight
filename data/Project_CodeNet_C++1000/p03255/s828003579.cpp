#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; long long int Y; 
	cin >> N >> Y; 
	long long int X[200010] = {}; 
	long long int S[200010] = {}; 
	for(int i = 0; i < N; i++){
		cin >> X[N - i]; 
	}
	long long int C[200010] = {}; // 係数
	C[0] = 5; C[1] = 5; 
	for(int i = 2; i <= N; i++){
		C[i] = C[i-1] + 2; 
	}
	for(int i = 1; i <= N; i++){
		S[i] = S[i-1] + X[i]; 
	}
	long long int M[200010] = {}; // i回に分けて捨てるときの最小値
	long long int INF = 2e15; // どこかで打ち切らないと、最適でないケースでlonglongでも溢れるぞ
	for(int i = 1; i <= (N+1)/2; i++){
		long long int tmp = (long long) (N + i) * Y; 
		int k = N / i; 
		for(int j = 0; j < k; j++){
			tmp += C[j] * (S[(j+1) * i] - S[j * i]); 
			if(tmp > INF) break; 
		}
		tmp += C[k] * (S[N] - S[k * i]); 
		M[i] = min(tmp, INF); 
	}
	long long int ans = INF; 
	for(int i = 1; i <= (N+1)/2; i++){
		ans = min(M[i], ans); 
	}
	cout << ans << endl; 
}