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

	int n; cin>>n;
	vector<int> a(n + 2);
	a[0] = a[n + 1] = 0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	ll sum = 0;
	for(int i = 1; i <= n + 1; i++){
		sum += abs(a[i] - a[i - 1]);
	}
	for(int i = 1; i <= n; i++){
		cout<<sum - abs(a[i + 1] - a[i]) - abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i - 1])<<'\n';
	}

	return 0;
}