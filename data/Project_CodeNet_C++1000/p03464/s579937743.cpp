#include<bits/stdc++.h>
using namespace std;

int A[100003] , K; long long mn , mx;

int main(){
	cin >> K; for(int i = 1 ; i <= K ; ++i) cin >> A[i];
	if(A[K] != 2){cout << -1; return 0;}
	mn = 2; mx = 3;
	for(int i = K ; i ; --i){
		long long p = (mn + A[i] - 1) / A[i] , q = mx / A[i];
		if(p > q){cout << -1; return 0;}
		mn = p * A[i]; mx = q * A[i] + A[i] - 1;
	}
	cout << mn << ' ' << mx; return 0;
}