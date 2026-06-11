#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	map<int, int> mp1;
	rep(i, n){
		int d;
		cin >> d;

		if(mp1.count(d) == 0) mp1[d] = 0;
		mp1[d]++;
	}

	int m;
	cin >> m;

	map<int, int> mp2;
	rep(i, m){
		int t;
		cin >> t;

		if(mp2.count(t) == 0) mp2[t] = 0;
		mp2[t]++;
	}

	for(auto p : mp2){
		int k = p.first;
		int v = p.second;
		if(mp1.count(k) == 0 || mp1[k] < v){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
}
