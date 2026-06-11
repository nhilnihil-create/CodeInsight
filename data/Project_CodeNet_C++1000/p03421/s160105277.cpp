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

typedef unsigned long long llu;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const ll MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;

int ans[300001];
int n, mav, idx;

// 길이 x의 그룹 rotn개를 만든다.
void makes(int len, int rotn) {
	mav = n;
	for (int i = 0; i < rotn; i++) {
		mav -= len;
		for (int j = 1; j <= len; j++)
			ans[j + len * i] = mav + j;
	}
}

int main() {
	int l, d;
	scanf("%d %d %d", &n, &l, &d);

	int k = n / l;
	if (n % l) k++;

	if (n + 1 < d + l) return !printf("-1");
	if (d < k) return !printf("-1");

	int ro, rr;
	for (ro = k; ro >= 1; ro--) {
		rr = n - ro * l; // ro * l개의 수를 사용
		rr += ro; // 온전한 그룹 개수 + 1개의 가중치를 받음.

		if (rr >= d) break;
	}

	// rr개의 수를 확보할 수 있음.
	// 온전한 그룹 rr - d개 만큼 남은 그룹을 만들고
	// 그 나머지는 내림차순으로 배치한다.
	// d - ro개의 추가 설치가 필요함.
	// mav부터 rr - d개 설치.
	
	rr++;
	makes(l, ro);
	idx = l * ro + 1;
	
	mav -= rr - d - 1;
	for (int i = 0; i < rr - d; i++)
		ans[idx++] = mav + i;
	mav--;
	for (int i = idx; i <= n; i++)
		ans[i] = mav--;

	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
}