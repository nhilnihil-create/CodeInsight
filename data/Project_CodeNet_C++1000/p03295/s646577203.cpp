#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

bool cmp(pair<int, int> a, pair<int, int> b){
	return (a.second == b.second)?(a.first < b.first):(a.second < b.second);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	vector<pair<int, int> > a(m);
	for(int i = 0; i < m; i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a.begin(), a.end(), cmp);
	int cur = 0, ans = 0;
	for(int i = 0; i < m; i++){
		if(a[i].first < cur)continue;
		cur = a[i].second; ans++;
	}
	cout<<ans<<endl;

	return 0;
}