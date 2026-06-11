# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
typedef long long int ll;
using namespace std;
#define FOR(i,a,n) for(int i=(ll)a;i<(ll)n;++i)
#define TFOR(i,n)FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
const int INF = 1LL << 30;
const ll LLINF = 1LL << 60;
int main() {
	string s;
	cin >> s;
	int a=0, b=0, c=0;
	TFOR(i, s.size()) {
		if (s[i] == 'a')++a;
		if (s[i] == 'b')++b;
		if (s[i] == 'c')++c;
	}
	cout << (max(abs(a - b), max(abs(b - c), abs(c - a))) <= 1 ? "YES" : "NO") << endl;
	return 0;
}