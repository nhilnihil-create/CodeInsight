#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#define _USE_MATH_DEFINES
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0,1,0,-1 };
const ll dy[4] = { -1, 0, 1,0 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
double mysqrt(double x) {
	double l = 0, r = x;
	for (int i = 0; i < 64; ++i) {
		double m = (l + r) / 2.0;
		if (m*m < x)l = m;
		else r = m;
	}
	return l;
}
///////////////////////////////////////

//上下左右は独立して考える
//必要十分条件を考える
//iターン目の先手が手を打った直後に[l,r]にロボットが存在するためには
//s[i]==Lなら[l+1,r]にロボットが存在する必要がある
//s[i]=Rなら[l,r-1]にロボットが存在している必要がある
//さらにiターン目の後手が手を打った直後に[l,r]にロボットが存在するようにするためには
//t[i]=Lなら[l,min(r+1,w-1)]にロボットが存在すること
//t[i]=Rなら[max(0,l-1),r]にロボットが存在すること
//とも言える
int main() {
	int H, W, N; cin >> H >> W >> N;
	int sr, sc; cin >> sr >> sc;
	sr -- ; sc--;
	string S, T; cin >> S >> T;
	int L = 0;
	int R = W - 1;
	int U = 0;
	int D = H - 1;
	for (int i = N-1; i >=0; --i) {
		if (T[i] == 'R') {
			L = max(0, L - 1);
		}
		else if (T[i] == 'L') {
			R = min(W - 1, R + 1);
		}
		else if (T[i] == 'D') {
			U = max(0, U - 1);
		}
		else {
			D = min(H - 1, D + 1);
		}
		
		if (S[i] == 'R') {
			R -= 1;
		}
		else if(S[i]=='L'){
			L += 1;
		}
		else if (S[i] == 'D') {
			D -= 1;
		}
		else {
			U += 1;
		}
		if (R < 0 || L >= W || U >= H || W < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (L <= sc && sc <= R && U <= sr && sr <= D) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}