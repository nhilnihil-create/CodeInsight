#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int A, B;
	string S;
	cin >> A >> B >> S;
	rep(i,A) {
		if (S[i]-'0'<0 || S[i]-'9'>0) {
			cout << "No" << endl;
			return 0;
		}
	}
	if (S[A] != '-') {
		cout << "No" << endl;
		return 0;
	}
	rep(i,B) {
		if (S[i+A+1]-'0'<0 || S[i+A+1]-'9'>0) {
			cout << "No" << endl;
			return 0;
		}
	}
	 cout << "Yes" << endl;

	return 0;
}
