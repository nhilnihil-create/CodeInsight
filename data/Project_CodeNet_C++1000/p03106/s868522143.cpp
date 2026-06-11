#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

vector<int> div(int n){
	
	vector<int> div;

	for (int i=1; i*i <= n; i++){
		if (!(n%i)){
			div.push_back(i);
			div.push_back(n/i);
		}
	}

	sort(div.begin(), div.end());
	return div;
}

int main(){

	int ia, ib, k, gcd = 1, cont = 0, x = 0, flag = 1;
	scanf("%d %d %d", &ia, &ib, &k);

	vector<int> a, b, c;
	a = div(ia);
	b = div(ib);

	for (auto i : a){
		for (auto j : b){
			
			if (i == j){
				for (auto k : c) if (k==i) flag = 0;
				if (flag) c.push_back(i);
			}
			flag = 1;
		}
	}
		
	printf("\n%d\n", c[c.size()-k]);
	return 0;
}
