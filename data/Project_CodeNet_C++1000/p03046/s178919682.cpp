#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 998244353;
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

//gcd,lcm,べき,二進展開
//組み合わせ、mod計算
//最短路問題、bit、union find

///////////////////////////



	
int main() {	
	
	ll M, K;
	cin >> M >> K;

	ll a[MAX];

	ll N = pow(2, M);

	if (M == 0) {
		if (K == 0) { cout << "0 0"; }
		else { cout << "-1"; }
	}

	else if (M == 1) {
		if (K == 0) { cout << "0 0 1 1"; }
		else { cout << "-1"; }
	}

	else if (K >= N) { cout << -1; }

	else {
		rep(i, N) {
			if (i != K) { cout << i<<" "; }
		}
		cout << K <<" ";
		
		rep(i, N) {
			if (N - 1 - i != K) { cout << N - 1 - i << " "; }
		}


		cout << K;

	}

	system("PAUSE");


}