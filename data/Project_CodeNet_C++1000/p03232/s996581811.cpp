#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();}
	return a;
}
const int MOD = 1e9 + 7;
int arr[100003] , N , inv[100003] , jc;

int poww(long long a , int b){
	int times = 1;
	while(b){if(b & 1) times = times * a % MOD; a = a * a % MOD; b >>= 1;}
	return times;
}

int main(){
	N = read(); for(int i = 1 ; i <= N ; ++i) arr[i] = read();
	jc = 1; for(int i = 1 ; i <= N ; ++i) jc = 1ll * jc * i % MOD;
	for(int i = 1 ; i <= N ; ++i) inv[i] = (poww(i , MOD - 2) + inv[i - 1]) % MOD;
	int sum = 0;
	for(int i = 1 ; i <= N ; ++i)
		sum = (sum + (inv[i] + inv[N - i + 1] - inv[1] + 1ll * MOD) * arr[i]) % MOD;
	cout << 1ll * sum * jc % MOD; return 0;
}