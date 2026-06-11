#include <bits/stdc++.h>

using namespace std;

const int maxn = 300010, p = 998244353;

#define ll long long

int n, A, B;
ll k;
int fact[maxn + 5];

int add(int a, int b){
	return ((ll) a + b) % p;
}

int mul(int a, int b){
	return ((ll) a * b) % p;
}

int pot(int x){
	int arr[38];
	arr[0] = x;
	
	for(int i = 1; i < 31; i++){
		arr[i] = mul(arr[i - 1], arr[i - 1]);
	}
	
	int sol = 1;
	
	for(int i = 0; i < 31; i++){
		if((p - 2) & (1 << i)) sol = mul(sol, arr[i]);
	}
	
	return sol;
}

int divi(int a, int b){	
	return mul(a, pot(b));
}

int main(){
	cin >> n >> A >> B >> k;
	
	fact[0] = 1;
	
	for(int i = 1; i < maxn; i++) fact[i] = mul(fact[i - 1], i);
	
	int sum = 0;
		
	for(int a = 0; a <= n; a++){
		ll x = (ll)a * (ll)A;
		int b;
		
		if(k < x) continue;
		
		if((k - x) % B != 0) continue;
		
		b = (k - x) / B;
		
		if(b > n) continue;
		
		int c = divi(fact[n], fact[n - a]);
		int d = divi(fact[n], fact[n - b]);
		int e = divi(c, fact[a]);
		int f = divi(d, fact[b]);		
		
		sum = add(sum, mul(e, f));
	}
	
	cout << sum;

	return 0;
}