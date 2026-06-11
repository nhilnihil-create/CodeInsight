#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int _;
		cin >> _;
	}
	
	if(((n-1) % (k-1)) == 0) {
		cout << (n-1) / (k-1);
	} else {
		cout << ((n-1) / (k-1)) + 1;
		
		// ceil((n-k) / (k-1)) + 1;
		// ((n-k + (k-1) - 1) / (k-1)) + 1
		// (n-k+k-1/k-1) + 1
		// (n-1/k-1) + 1
	}
}
