#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

bitset<8055> TX, TY;

char A[8055];
vector<int> XV, YV;

int N, X, Y, DX, DY;

int main() {
	scanf(" %s%d%d", A, &X, &Y);
	N = strlen(A);
	int i = 0;
	for(; i < N && 'F' == A[i]; i++) X--;
	for(int c = 0; i < N; i++) {
		if('T' == A[i]) {
			if(DX) {
				XV.eb(DX);
				DX = 0;
			}
			if(DY) {
				YV.eb(DY);
				DY = 0;
			}
			c ^= 1;
		}
		if('F' == A[i]) (c ? DY : DX)++;
	}
	if(DX) {
		XV.eb(DX);
		DX = 0;
	}
	if(DY) {
		YV.eb(DY);
		DY = 0;
	}
	X = abs(X); Y = abs(Y);

	TX[0] = TY[0] = true;
	for(int v : XV) {
		TX = (TX<<v) | (TX>>v);
	}
	for(int v : YV) {
		TY = (TY<<v) | (TY>>v);
	}
	puts(TX[X] && TY[Y] ? "Yes" : "No");
	return 0;
}