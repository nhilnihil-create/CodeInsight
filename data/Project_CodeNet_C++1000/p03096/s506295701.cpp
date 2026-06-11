#include <bits/stdc++.h>
using namespace std;
#define LL long long

int N;
int A[200010], pre[200010], suc[200010], H[200010], f[200010];
LL pp = (1e9) + 7;

int main(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> A[i];
		pre[i] = H[A[i]];
		suc[H[A[i]]] = i;
		H[A[i]] = i;
	}
	f[N] = 1;
	for (int i = N - 1; i >= 1; i--){
		f[i] = f[i + 1];
		if ((suc[i] != 0) & (suc[i] > i + 1))
			f[i] = (f[i] + f[suc[i]]) % pp;
	}
	cout << f[1] << endl;
}