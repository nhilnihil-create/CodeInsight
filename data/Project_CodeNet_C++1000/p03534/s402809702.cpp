#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<queue>
#include<map>

using namespace std;
#define REP(i,m,n) for(long long i=m;i<n;++i)
#define INF 10000000000000000
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define all(v) v.begin(),v.end()

vector<int>v(5, 0);

int main() {
	string s;
	cin >> s;
	REP(i, 0, s.size()) {
		if (s[i] == 'a') {
			v[0]++;
		}
		else if (s[i] == 'b') {
			v[1]++;
		}
		else {
			v[2]++;
		}
	}
	if (abs(v[1] - v[0]) < 2 && abs(v[2] - v[1]) < 2 && abs(v[0] - v[2]) < 2) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}