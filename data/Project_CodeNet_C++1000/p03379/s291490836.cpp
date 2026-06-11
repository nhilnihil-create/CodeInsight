#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	vector<pair<int, int> > a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int> pos(n);
	for(int i = 0; i < n; i++){
		pos[a[i].second] = i;
	}
	int k = n/2;
	for(int i = 0; i < n; i++){
		if(pos[i] >= k)cout<<a[k - 1].first<<'\n';
		else cout<<a[k].first<<'\n';
	}

	return 0;
}