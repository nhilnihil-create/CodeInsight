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
const ll INF = 1e9 + 7;
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

//書いてある数が最大のボールを一つ考える
//それをi番目のボールとするこの時i番目のボールのペアとなるボールｊがあるとしたら
//Ai<Ai+Aj<=2*AiよりAi+Ajの値は一意に定まる
//よってAi＋Ajが２べきとなるようなjがあるとしたらi番目のボールとj番目のボールをペアにしてよい

int mypow(int b, int n) {
	if (n == 0)return 1;
	if (n == 1)return b;
	if (n % 2 == 0) {
		return mypow(b*b, n / 2);
	}
	else {
		return mypow(n, n - 1)*b;
	}
}
//n<2^kなる最小の2^kを返す
int minbeki(int n) {
	int ret = 1;
	while (n >= ret) {
		ret *= 2;
	}
	return ret;
}
int main() {
	int N; cin >> N;
	map<int, int>cnt;
	//key=書かれた整数,value=ボールの個数
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (cnt.find(a) == cnt.end())cnt[a] = 0;
		++cnt[a];
	}
	int ans = 0;
	for (auto itr = cnt.rbegin(); itr != cnt.rend(); ++itr) {
		int b = itr->first;
		if (cnt[b] == 0)continue;
		int a = minbeki(b) - b;
		if (a == b) {
			//bと書かれたボール同士でペアを作る
			ans += cnt[b] / 2;
		}
		else {
			if (cnt.find(a) == cnt.end())continue;
			//aと書かれたボールが存在しなければ次へ
			//少ないほうに合わせてペアを作る
			ans += min(cnt[a], cnt[b]);
			cnt[a] -= min(cnt[a], cnt[b]);
		}
	}
	cout << ans << endl;
	return 0;
}