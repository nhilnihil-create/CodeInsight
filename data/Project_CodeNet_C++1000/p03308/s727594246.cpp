#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);

	sort(a.begin(), a.end());

	cout << a.back()-a.at(0) << endl;
}