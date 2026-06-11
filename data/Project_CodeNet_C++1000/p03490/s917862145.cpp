#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <string>
#include <bitset>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <unordered_map>
#include <array>
using namespace std;
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;


int main() {
	pair<long, long> dir(1,0);
	string s;

	long x = 0;
	long y = 0;
	long x_t, y_t;
	cin >> s;
	s += 'T';
	long N = s.length();
	cin >> x_t >> y_t;
	vector<int> a;
	vector<int> b;
	int temp=0;
	bool flag=true;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'T') {
			if (flag) {
				a.push_back(temp);
				temp = 0;
			}
			else {
				b.push_back(temp);
				temp = 0;
			}
			flag = !flag;
		}
		else temp++;
	}
	x_t -= *a.begin();
	a.erase(a.begin());

	set<int> A;
	A.insert(x);
	for (auto i : a) {
		set<int>A_;
		for (auto j : A) {
			A_.insert(j + i);
			A_.insert(j - i);
		}
		A = A_;
	}
	set<int> B;
	B.insert(y);
	for (auto i : b) {
		set<int>B_;
		for (auto j : B) {
			B_.insert(j + i);
			B_.insert(j - i);
		}
		B = B_;
	}

	string ans = A.find(x_t)!=A.end()&&B.count(y_t)>0?
		"Yes" : "No";
	cout << ans;


	return 0;
}
