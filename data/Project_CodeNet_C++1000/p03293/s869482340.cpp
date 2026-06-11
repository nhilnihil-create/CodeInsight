#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string S, T;
	cin >> S >> T;

	string copy = S + S;
	// cout << copy << endl;
	rep(i, (int)(S.size())){
		rep(n, (int)(T.size())){
			// cout << "1" << endl;
			// cout << copy.at(i + n) << T.at(n) << endl;
			if (copy.at(i + n) != T.at(n)) break;
			if (n + 1 == (int)(T.size())){
				cout << "Yes" << endl;
				return 0;
			}
			// cout << "o" << endl;
		}
	}
	cout << "No" << endl;
}