#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int N,Z,W;
	cin >> N >> Z >> W;
	vector<int> a(N);

	rep(i,N)
		cin >> a.at(i);

	if(N == 1)
		cout << abs(a.at(0)-W);
	else
		cout << max(abs(a.at(N-1)-W), abs(a.at(N-2)-a.at(N-1)));
	cout << endl;
}