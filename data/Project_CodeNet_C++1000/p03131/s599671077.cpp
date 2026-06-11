#define _USE_MATH_DEFINES
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>
#include<stdbool.h>
#include<math.h>
typedef long long ll;
#define N (1000000000+7)
using namespace std;
typedef pair<int, int> P;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

ll prime[100010];
ll kaijo[200010];
void init() {
	kaijo[0] = 1;
	for (ll i = 1;i <= 200000;i++)kaijo[i] = (kaijo[i - 1] * i) % N;
}

ll inv(ll x) {
	ll res = 1;
	ll k = N - 2;
	ll y = x;
	while (k) {
		if (k & 1)res = (res*y) % N;
		y = (y%N*y%N) % N;
		k /= 2;
	}
	return res;
}

ll Comb(ll n, ll k) {
	ll b = kaijo[n];
	ll c = kaijo[n - k];
	ll d = kaijo[k];
	ll cd = (c*d) % N;
	return ((b%N)*(inv(cd)%N) + N) % N;
}


int main(void) {
	ll k, a, b, ans = 0;
	cin >> k >> a >> b;
	if (k<=a||b-a<=2) {
		cout << k + 1 << endl;
		return 0;
	}
	ll num = k + 1 - a;
	if (num % 2 == 0) {
		ans = a+(b-a)*(num/2);
	}
	else {
        num--;
		ans = (num / 2)*(b - a) + a + 1;
	}
	
	cout <<  ans << endl;
}
