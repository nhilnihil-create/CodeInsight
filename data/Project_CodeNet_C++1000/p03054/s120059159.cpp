#include <iostream>
#include <cstdio>
using namespace std;

int h, w, n, sr, sc;
string s, t;

int f(int p, int q, char x, char y) {
	int i, k;
	for(i=0, k=p; i<n; i++) {
		if(s[i]==x) k--;
		if(k<=0) return 1;
		if(t[i]==y) k = min(q, k+1);
	}
	for(i=0, k=p; i<n; i++) {
		if(s[i]==y) k++;
		if(k>q) return 1;
		if(t[i]==x) k = max(1, k-1);
	}
	return 0;
}

int main() {
	cin >> h >> w >> n >> sr >> sc >> s >> t;
	if(f(sc, w, 'L', 'R') || f(sr, h, 'U', 'D')) puts("NO");
	else puts("YES");
	return 0;
}