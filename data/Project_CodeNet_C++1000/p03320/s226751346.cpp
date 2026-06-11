#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const ll MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<string> v;

char s[18], tt[18];
char temp[18];

pli trans(char ss[18]) {
	ll ret, t;
	int sum = 0;
	sscanf(ss, "%lld", &ret);
	t = ret;

	while (t) {
		sum += t % 10;
		t /= 10;
	}

	return pli(ret, sum);
}

int n;
void go(int o, int sst) {
	if (o == n) return;

	go(o + 1, 0);
	for (int i = '8'; i >= '0'; i--) {
		if (sst && i == '0') break;
 		memcpy(temp, s, sizeof(temp));
		temp[o] = i;

		// printf("%s////\n", temp);

		pli k = trans(s), kk = trans(temp);
		// 이게 앞에서부터 채우면 이렇게 되나??
		// 

		if (k.first * kk.second >= kk.first * k.second) {
			string st = temp;
			v.push_back(st);
			s[o] = i;
			go(o + 1, sst & (i == '0'));
			s[o] = '9';
		}
		else break;
	}
}

int main() {
	int k;
	scanf("%d", &k);


	// 14자리 쓰는 것.
	for (int i = 14; i >= 0; i--) {
		memset(s, 0, sizeof(s));

		for (int j = 0; j <= i; j++)
			s[j] = '9';

		string st = s;
		v.push_back(st);
		
		n = i + 1;
		go(0, 1);
	}

	int cnt = 0;
	for (auto i = v.rbegin(); cnt < k; i++) {
		printf("%s\n", i->c_str());
		cnt++;
	}
}