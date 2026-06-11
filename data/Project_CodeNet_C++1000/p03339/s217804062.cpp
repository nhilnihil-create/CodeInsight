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
	string s;
	cin>>n>>s;
	vector<int> e(n), w(n);
	for(int i = 0; i < n; i++){
		e[i] = (s[i] == 'E');
		if(i)e[i] += e[i - 1];
	}
	for(int i = n - 1; i >= 0; i--){
		w[i] = (s[i] == 'W');
		if(i + 1 < n)w[i] += w[i + 1];
	}
	int ans = n;
	for(int i = 0; i < n; i++){
		int tmp = 0;
		if(i)tmp += e[i - 1];
		if(i + 1 < n)tmp += w[i + 1];
		ans = min(ans, n - 1 -tmp);
	}
	cout<<ans<<endl;

	return 0;
}