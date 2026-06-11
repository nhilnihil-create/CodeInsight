#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

ll gcd(ll x, ll y){
	if(y == 0){
		return x;
	}
	x %= y;
	return gcd(y, x);
}

int main(){
	int T;
	cin >> T;
	ll A[T], B[T], C[T], D[T];
	for(int i=0; i<T; i++){
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for(int i=0; i<T; i++){
		if(A[i] < B[i] || B[i] > D[i]){
			cout << "No" << endl;
			continue;
		}
		ll b = B[i] - 1 - ((B[i] - 1 - (A[i] % B[i]))%gcd(B[i], D[i]));
		if(b > C[i]){
			cout << "No" << endl;
		}else{
			cout << "Yes" << endl;
		}
	}
	return 0;
}