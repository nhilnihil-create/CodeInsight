#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string s;
	cin >> s;
	int a[4];
	rep(i,4) a[i] = s[i] - '0';
	
	rep(i,8) {
		int result = a[0];
		rep(j,3) {
			result += pow(-1,i>>j&1)*a[j+1];
		}

		if (result == 7) {
			cout << a[0];
			rep(j,3) {
				if (!(i>>j&1)) cout << '+';
				else cout << '-';
				cout << a[j+1];
			}
			cout << "=7" << endl;
			return 0;
		}
	}

	return 0;
}
