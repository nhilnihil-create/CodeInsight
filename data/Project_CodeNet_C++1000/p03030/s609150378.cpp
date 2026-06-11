#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<string, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int n;
	cin >> n;
	vector<pair<P,int>>pai;
	set<string>ss;
	rep(i, n) {
		string s;
		int p;
		cin >> s >> p;
		P pp = make_pair(s, -p);
		pai.emplace_back(make_pair(pp, i));
	}
	sort(pai.begin(), pai.end());
	rep(i, n) {
		cout << pai[i].second +1<< endl;
	}
	return 0;
}