#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
int main() {
	string s;int k, sum = 0, su = 0;cin >> k >> s;
	rep(i, k) {
		if (s[i] == 'R') sum++;
		else su++;
	}
	if (sum > su) cout << "Yes" << endl;
	else cout << "No" << endl;
}