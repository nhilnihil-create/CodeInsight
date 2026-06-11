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
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}



///////////////////////////




int main() {

	ll A, B;
	cin >> A >> B;

	ll h = 100;
	ll w = 100;

	char grid[101][101];

	repn(i, 100)repn(j, 50) {
		grid[i][j] = '#';
		grid[i][j+50] = '.';
	}
	
	ll I = 2;
	ll J = 2;
	repn(i,A-1){
		grid[I][J] = '.';
		I += 2;
		if (I == 100) { I = 2; J += 2; }
	}
	
	I = 2;
	J = 52;
	repn(i, B - 1) {
		grid[I][J] = '#';
		I += 2;
		if (I == 100) { I = 2; J += 2; }
	}
	
	cout << h << " " << w << endl;
	repn(i, 100) {
		repn(j, 100) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	system("PAUSE");

}
