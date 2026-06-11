#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char> > vec(h, vector<char>(w));
	rep(i, h) {
		rep(j, w) cin >> vec.at(i).at(j);
	}
	string res = "Yes";
	rep(i, h) {
		rep(j, w) {
			int cnt = 0;
			if (vec.at(i).at(j)=='#') {
				if (i>0) {
					if (vec.at(i-1).at(j)=='#') cnt++;
				}
				if (i<h-1) {
					if (vec.at(i+1).at(j)=='#') cnt++;
				}
				if (j<w-1) {
					if (vec.at(i).at(j+1)=='#') cnt++;
				}
				if (j>0) {
					if (vec.at(i).at(j-1)=='#') cnt++;
				}
				if (cnt==0) res = "No";
			}
		}
	}
	cout << res << endl;
}