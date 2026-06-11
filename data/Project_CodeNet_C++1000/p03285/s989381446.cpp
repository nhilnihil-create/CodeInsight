#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int n; cin >> n;
	rep(i,25){
		rep(y,14){
			if(4*i+7*y==n){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}

