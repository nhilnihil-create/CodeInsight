#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n;
	vector<int> a(n), b;
	for(int i = 0; i < n; i++)cin >> a[i];


	for(int i = 0; i < n; i++) {
		if(a[i] - 1 > (int)b.size()) {
			cout << -1 << endl;
			return 0;
		}
		b.insert(b.begin() + a[i] - 1, a[i]);
	}
	for(auto i : b)cout << i << endl;

}