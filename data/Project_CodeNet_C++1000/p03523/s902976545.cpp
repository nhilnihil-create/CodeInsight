#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main() {
	string S;
	cin >> S;
	smatch smatch;

	if(regex_search(S, smatch, regex("^A{0,1}KIHA{0,1}BA{0,1}RA{0,1}$"))) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}