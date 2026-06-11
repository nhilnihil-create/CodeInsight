#include <bits/stdc++.h>
using namespace std;

signed main(){
	int H, W, h, w;
	scanf("%d%d%d%d", &H, &W, &h, &w);
	printf("%d\n", (H - h) * (W - w));
	return 0;
}