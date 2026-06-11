#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int N,H,W,c=0;
	cin >> N >> H >> W;

	rep(i,N) {
		int A,B;
		cin >> A >> B;
		if(A>=H && B>=W)
			++c;
	}

	cout << c << endl;
}