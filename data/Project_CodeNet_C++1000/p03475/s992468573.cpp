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
	vector<int> c(n), s(n), f(n);
	for(int i = 0; i + 1 < n; i++){
		cin>>c[i]>>s[i]>>f[i];
	}
	for(int i = 0; i + 1 < n; i++){
		int st = 0;
		for(int j = i; j + 1 < n; j++){
			st = max(s[j], ((st + f[j] - 1)/f[j])*f[j]);
			st += c[j];
		}
		cout<<st<<'\n';
	}
	cout<<0<<'\n';

	return 0;
}