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

	string s; cin>>s;
	int n = s.size();
	int ans = n;
	for(int i = 1; i < n; i++){
		if(s[i] != s[i - 1])ans = min(ans, max(i, n - i));
	}
	cout<<ans<<'\n';

	return 0;
}