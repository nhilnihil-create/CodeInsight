#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
int main() {
	string s;
	cin >> s;
	int cnt = 0;
	rep(i, s.size()) {
		if (s[i] == '2') {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
