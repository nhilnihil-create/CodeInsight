#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, en, len;
vector<int> gr[200005];

void f(int u, int pr, int dt) {
	if(dt > len) len = dt, en = u;
	for(auto v:gr[u]) if(v!=pr) f(v, u, dt+1);
}

int main() {
	int i, t1, t2;
	cin >> n;
	while(--n) {
		scanf("%d%d", &t1, &t2);
		gr[t1].push_back(t2);
		gr[t2].push_back(t1);
	}
	f(1, 0, 0);
	f(en, 0, 0);
	puts(len%3==1 ? "Second" : "First");
	return 0;
}