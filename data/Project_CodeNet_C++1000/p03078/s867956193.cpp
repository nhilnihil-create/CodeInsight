#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxx = 1e3 + 7;
int x, y, z, k;
LL a[maxx], b[maxx], c[maxx];
vector <LL> vec;
priority_queue <LL> qua;
LL tmp[3 * maxx];

void Init() {
	scanf("%d %d %d %d", &x, &y, &z, &k);
	for(int i = 1; i <= x; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= y; i++) scanf("%lld", &b[i]);
	for(int i = 1; i <= z; i++) scanf("%lld", &c[i]);
}

int main() {
	Init();
	for(int i = 1; i <= x; i++) {
		for(int j = 1; j <= y; j++) {
			LL num = a[i] + b[j];
			qua.push(num);
		}
	}
	int cnt = 0;
	while(!qua.empty()) {
		if(cnt < k) tmp[++cnt] = qua.top();
		qua.pop();
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= z; j++) {
			LL num = tmp[i] + c[j];
			qua.push(num);
		}
	}
	int tot = 0;
	while(!qua.empty()) {
		tot++;
		printf("%lld\n", qua.top());
		qua.pop();
		if(tot == k) break;
	}
	return 0;
}