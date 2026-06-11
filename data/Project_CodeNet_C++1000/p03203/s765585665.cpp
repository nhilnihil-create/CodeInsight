#include <iostream>
#include <cstdio>
using namespace std;

int h, w, n, r, c, to, mn[200005];
int main() {
	int i;
	cin >> h >> w >> n;
	for(i=1; i<=h; i++) mn[i] = 1e9;
	while(n--) {
		scanf("%d%d", &r, &c);
		mn[r] = min(mn[r], c);
	}
	for(i=1; i<=h; i++) {
		if(mn[i] <= to) break;
		if(to+1 < mn[i]) to++;
	}
	cout << i-1;
	return 0;
}