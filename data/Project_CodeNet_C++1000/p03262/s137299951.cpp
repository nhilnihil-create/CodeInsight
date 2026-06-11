#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



ll gcd(ll x,ll y){

	x = abs(x);
	y = abs(y);

	if(x < y){
		swap(x,y);
	}
	if(y == 0){
		return x;
	}else{
		return gcd(y,x%y);
	}
}

ll N,X;
vector<ll> V;

int main(){

	scanf("%lld %lld",&N,&X);
	V.push_back(X);

	ll tmp;
	for(ll i = 0; i < N; i++){

		scanf("%lld",&tmp);
		V.push_back(tmp);
	}

	sort(V.begin(),V.end());

	ll base = V[1]-V[0];
	for(int i = 1; i < V.size()-1; i++){

		base = gcd(base,V[i+1]-V[i]);
	}

	printf("%lld\n",base);

	return 0;
}
