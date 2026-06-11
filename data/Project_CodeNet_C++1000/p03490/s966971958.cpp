#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool xt[16009][8009], yt[16009][8009];

void go(bool st[][8009], vector<int> &S, int x, int i, int &f, int d) {
	if(x == d && i == S.size()) f = 1;
	if(i == S.size()) return;
	st[x+8000][i] = 1;
	if(!st[x+S[i]+8000][i+1]) go(st, S, x+S[i], i+1, f, d);
	if(!st[x-S[i]+8000][i+1]) go(st, S, x-S[i], i+1, f, d);
}

int main() {
	vector<int> XS, YS;
	string S; cin >> S;
	int N = S.size(), x, y; scanf("%d%d",&x,&y);
	for(int i=0, c=0, f=0; i<N; i++) {
		if(S[i] == 'F') ++c;
		if(S[i] == 'T' || i+1 == N) {
			if(f == 0) {
				if(YS.empty()) x -= c;
				else XS.push_back(c);
			}
			if(f == 1) YS.push_back(c);
			f = !f; c = 0;
		}
	}
	int xf = 0, yf = 0;
	go(xt, XS, 0, 0, xf, x); go(yt, YS, 0, 0, yf, y);
	if(xf && yf) puts("Yes");
	else puts("No");
	return 0;	
}