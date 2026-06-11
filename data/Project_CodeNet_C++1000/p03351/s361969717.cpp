#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if(abs(c-a) <=d||(abs(a-b)<=d&&abs(b-c)<=d)){
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}
