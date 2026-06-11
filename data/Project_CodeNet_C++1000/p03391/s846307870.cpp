#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	bool all_same=true;
	ll s=0, m=LLONG_MAX;
	for(int i=0; i<n; i++){
		ll a, b;
		cin >> a >> b;
		if(a!=b) all_same=false;
		s+=a;
		if(a>b) m=min(m, b);
	}

	if(all_same) cout << 0 << endl;
	else cout << s-m << endl;
	return 0;
}