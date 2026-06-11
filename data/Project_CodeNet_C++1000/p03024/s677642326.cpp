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
	string s;int k,sum = 0;cin >> s;k = s.size();
	rep(i, k) {
		if (s[i] == 'o') sum++;
	}
	if (15 - k + sum >= 8) cout << "YES" << endl;
	else cout << "NO" << endl;
}