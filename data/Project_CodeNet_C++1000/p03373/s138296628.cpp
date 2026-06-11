#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#include<map>
#define int long long
using namespace std;

signed main() {
	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;
	C = C * 2;
	int answer = 0;
	if(A + B >= C) {
		int cnt = min(X,Y);
		answer += cnt * C;
		X -= cnt;
		Y -= cnt;
		if(X == 0) {
			answer += min(Y * B,Y * C);
		}
		else {
			answer += min(X * A,X * C);
		}
	}
	else {
		answer = X * A + Y * B;
	}
	cout << answer << endl;
}