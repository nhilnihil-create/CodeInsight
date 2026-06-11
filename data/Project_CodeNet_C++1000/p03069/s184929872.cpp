#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF=1e9+7;

int main() {
	int N,w=0,b=0,r=INF;
	string S;
	cin >> N >> S;

	rep(i,N)
		w += S.at(i)=='.';

	rep(i,N) {
		r = min(r, b+w);
		b += S.at(i)=='#';
		w -= S.at(i)=='.';
	}

	cout << min(r, b+w) << endl;
}