#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int t;
long long a, b, c, d;

long long gcd(long long a, long long b){
	if(b == 0LL){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

void solve(){
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	if(b > d || b > a){
		printf("No\n");
		return;
	}
	// now b <= d
	if(c >= b - 1){
		printf("Yes\n");
		return;
	}
	// now c + 1 < b <= d
	// if it is possible to reach a number in [c + 1, b - 1],
	// then gg
	
	// first simulate up to first restock
	a -= (a / b) * b;
	
	// can assume restock is adding < 2b cans
	// indeed, can assume restock + consume is going from a to (a + d) % b
	// if any time this is >= c + 1, you lose
	long long g = gcd(d, b);
	// Largest x s.t. a + gx <= b - 1
	long long x = (b - 1 - a) / g;
	if(a + g * x >= c + 1){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}