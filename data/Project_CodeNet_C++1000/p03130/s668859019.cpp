#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cctype>
using namespace std;

#define Yes(a) a ? "Yes" : "No";
#define YES(a) a ? "YES" : "NO";
#define rep(i,n) for(int i=0;i<n;i++)

void sout(string* a, string* b) {
	if (*a > * b) {
		string c = *a;
		*a = *b;
		*b = c;
	}
}

int combination(int n, int k) {
	if (n > k && k > 0) {
		return (combination(n - 1, k) + combination(n - 1, k - 1));
	}
	else
		return 1;
}

int main() {
	int a[3], b[3];
	vector<int> s(4);
	for (int i = 0; i < 3; i++) {
		cin >> a[i] >> b[i];
		s.at(a[i] - 1)++;
		s.at(b[i] - 1)++;
	}
	sort(s.begin(), s.end());
	string ans;
	ans = YES(s.at(0) == 1 && s.at(1) == 1 && s.at(2) == 2);
	cout << ans << endl;
}