#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int arr[N];
int pre[N];
int ans;
int power(int a , int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b >>= 1;
	}
	return res;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		pre[i] = (pre[i - 1] + power(i , mod - 2)) % mod;
	}
	for(int i = 1 ; i <= n ; ++i){
		ans = (ans + 1LL * arr[i] * pre[i]) % mod;
		ans = (ans + 1LL * arr[i] * pre[n - i + 1]) % mod;
		ans = (ans + 1LL * arr[i] * (mod - 1LL)) % mod;
	}
	for(int i = 1 ; i <= n ; ++i){
		ans = (1LL * ans * i) % mod;
	}
	printf("%d\n" , ans);
}