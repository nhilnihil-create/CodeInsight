#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

char s[N], t[N];
int n;

bool check(int len, int p, char sub, char add){
	int l = 1, r = len;
	for (int i = n; i >= 1; i--){
		if (t[i] == add) l = max(l - 1, 1);
		else if (t[i] == sub) r = min(r + 1, len);
		if (s[i] == add) r--;
		else if (s[i] == sub) l++;
		if (l > r) return false;
	}
	return p >= l && p <= r;
}

int main(){
	int h, w, x, y;
	scanf("%d %d %d",&h,&w,&n);
	scanf("%d %d",&x,&y);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	if (check(h, x, 'U', 'D') && check(w, y, 'L', 'R')) printf("YES\n");
	else printf("NO\n");
	return 0;
}