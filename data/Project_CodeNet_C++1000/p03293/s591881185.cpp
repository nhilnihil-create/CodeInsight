#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main(){
	string s, t;
	bool f = 0;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) {
		s = s[s.size() - 1] + s;
		s.erase(s.end()-1);
		if (s == t)f = 1;
	}
	
	if (f == 1)cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}