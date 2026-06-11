#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int X[N], Y[N];
	rep(i,N) {
		int x;
		cin >> x;
		X[i] = x;
		Y[i] = x;
	}
	sort(Y, Y+N);
	rep(i,N) {
		if (X[i] <= Y[N/2-1]) cout << Y[N/2] << endl;
		else cout << Y[N/2-1] << endl;
	}

return 0;
}
