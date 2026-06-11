#include <bits/stdc++.h>
using namespace std;

int main(){	
	long long n;
	scanf("%lld",&n);
	vector<long long> a(n-1+1);
	for(int i = 0 ; i <= n-1 ; i++){
		scanf("%lld",&a[i]);
	}
	long long ai = 0, aj = -1000000000;
	for(int i = 0 ; i <= n-1 ; i++){
		ai = max(ai, a[i]);
	}
	for(int i = 0 ; i <= n-1 ; i++){
		if (abs(ai/2-aj)>abs(ai/2-a[i]) && a[i] < ai) aj = a[i];
	}
	cout << ai << " " << aj << endl;
	return 0;
}

