#include "bits/stdc++.h"
using namespace std;

int main() {
	static long long N, A, B[200010] = {}, ANS = 1000000000000;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		B[i + 1] = B[i] + A;
	}
	for (int i = 2; i <= N - 2; i++) {
		long long P, Q, R, S;
		long long X = B[i], Y = B[N] - B[i];
		int Left = 0, Right = i;
		while (Right - Left > 1) {
			int Mid = (Left + Right) / 2;
			if (B[Mid] * 2 <= X) Left = Mid;
			else Right = Mid;
		}
		P = max(B[Left], X - B[Right]), Q = min(B[Right], X - B[Left]);
		Left = i, Right = N;
		while (Right - Left > 1) {
			int Mid = (Left + Right) / 2;
			if ((B[Mid] - B[i]) * 2 <= Y) Left = Mid;
			else Right = Mid;
		}
		R = max(B[Left] - X, B[N] - B[Right]), S = min(B[Right] - X, B[N] - B[Left]);
		ANS = min(ANS, max(Q, S) - min(P, R));
	}
	cout << ANS;
}