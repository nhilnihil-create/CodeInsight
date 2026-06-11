#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int t_n = 0, x_n = 0, y_n = 0;
	rep(i,N){
		int t, x, y;
		bool flag = false;
		cin >> t >> x >> y;
		if (abs(x-x_n)+abs(y-y_n)>t-t_n) flag = true;
		else {
			int parity = (x-x_n + y-y_n)%2;
			parity = (parity+2)%2;
			if (parity != (t-t_n)%2) flag = true;
		}
		if (flag) {
			cout << "No" << endl;
			return 0;
		}
		t_n = t; x_n = x; y_n = y;
	}
	cout << "Yes" << endl;
	return 0;
}
