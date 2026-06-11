#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {
	int n;
	scanf("%d", &n);
	n--;
	int t = 0, a, b;
	;
	scanf("%d%d%d", &t, &a, &b);
	if ((abs(a - 0) + abs(b - 0) > t)
			|| (((abs(a - 0) + abs(b - 0)) & 1) && !(t & 1))
			|| (!((abs(a - 0) + abs(b - 0)) & 1) && (t & 1)))
		return printf("No\n"), 0;

	while (n--) {
		int desa, desb, nexttime;
		scanf("%d%d%d", &nexttime, &desa, &desb);
		if ((((abs(desa - a) + abs(desb - b)) & 1) && !((nexttime - t) & 1))
				|| (abs(desa - a) + abs(desb - b) > nexttime - t)
				|| (!((abs(desa - a) + abs(desb - b)) & 1)
						&& ((nexttime - t) & 1)))
			return printf("No\n"), 0;
		a = desa;
		b = desb;
		t = nexttime;
	}
	printf("Yes\n");
	return 0;
}
