#include <iostream>
#include <string>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
using namespace std;

string s;
char ope[3];
int main() {
	cin >> s;

	rep(bit, 0, 1 << 3){
		int sum = s[0] - '0';
		rep(i, 0, 3){
			int tmp = s[i+1] - '0';
			if(bit >> i & 1) sum += tmp;
			else sum -= tmp;
		}

		if(sum == 7) {
			rep(i, 0, 3) ope[i] = (bit >> i & 1) ? '+' : '-';
			break;
		}
	}

	rep(i, 0, 3) cout << s[i] << ope[i];
	cout << s[3] << "=7" << endl;

    return 0;
}
