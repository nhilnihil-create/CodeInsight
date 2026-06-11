#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){

	int n, lucro = 0;
	scanf("%d", &n);
	vector<int> v(n), c(n);

	rep(i,n) scanf("%d", &v[i]);
	rep(i,n){

		scanf("%d", &c[i]);
		if (v[i]>c[i]) lucro += v[i]-c[i];
	
	}
	printf("%d\n", lucro);
	return 0;
}