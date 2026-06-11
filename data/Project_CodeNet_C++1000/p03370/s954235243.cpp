#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int n,x;
	cin >> n >> x;
	vector <int> v(n);
	rep(i,n) cin >> v[i];
	sort(v.begin(), v.end());
	x-=accumulate(v.begin(), v.end(),0);
	cout << v.size() + x/v[0] << endl;
}
