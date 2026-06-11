#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	int k = 0;
	vector<char> ans;
	if (n==0) ans.push_back('0');
	while(n!=0) {
		char w;
		if (n%2) {
			w = '1';
			if(k%2) n = (n + 1) / 2;
			else n = (n - 1) / 2;
		}
		else {
			w = '0';
			n /= 2;
		}
		k++;
		ans.push_back(w);
	}
	int len = ans.size();
	for (int i=len-1;i>=0;i--) printf("%c", ans[i]);
	printf("\n");

	return 0;
}
