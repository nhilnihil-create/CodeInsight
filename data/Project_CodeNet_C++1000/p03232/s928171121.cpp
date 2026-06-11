#include <iostream>
using namespace std;
typedef long long ll;
ll N,A[100010],inf = 1e9+7;
ll fact[100010] = {0};
ll inv[100010] = {0};

ll mult(ll n, ll m){
	if(m==1) return n%inf;
	else if(m%2==0){
		ll t = mult(n,m/2);
		return (t*t)%inf;
	}else{
		ll t = mult(n,m-1);
		return (t*n)%inf;
	}
}

void factorial(ll N){
	for(ll i=0;i<=N;i++){
		if(i==0){
			fact[i] = 1;
			inv[i] = 1;
		}
		else{
			fact[i] = (i*fact[i-1])%inf;
			inv[i] = mult(i,inf-2);
		}
	}
}

int main(){
	cin >> N;
	factorial(N);
	ll ans = 0;
	for(int i=2;i<=N;i++){
		inv[i] += inv[i-1];
		inv[i] %= inf;
	}
	for(int i=1;i<=N;i++){
		cin >> A[i];
		ans += A[i]*((inv[i]+inv[N-i+1]-1+inf))%inf;
		ans %= inf;
	}
	cout << (ans*fact[N])%inf << endl;
}