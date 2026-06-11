#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int a,p,N,c=1,s=0;
	cin >> N >> a;
	p = a;

	rep(i,N-1) {
		cin >> a;
		if(p == a)
			++c;
		else {
			s += c/2;
			c = 1;
			p = a;
		}
	}

	cout << s+c/2 << endl;
}