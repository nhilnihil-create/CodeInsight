#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)

int main(){

	int n, x, sum = 0, menor = 1e5;
	
	scanf("%d %d", &n, &x);
	
	vector<int> m(n);
	
	rep(i,n){
		scanf("%d", &m[i]);
		if (m[i] < menor) menor = m[i]; 
		sum += m[i];
	}
	auto a = n + (x-sum)/menor;
	printf("%d\n", (sum <= x) ? a : 0 );
	return 0;
}

