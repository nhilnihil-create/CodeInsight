#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	vector<int> a(3);
	vector<int> b(3);
	rep(i, 3) cin >> a.at(i);
	b.at(0) = abs(a.at(0) - a.at(1));
	b.at(1) = abs(a.at(1) - a.at(2));
	b.at(2) = abs(a.at(2) - a.at(0));
	sort(b.begin(), b.end());
	cout << b.at(0) + b.at(1) << endl;
	return 0;
}