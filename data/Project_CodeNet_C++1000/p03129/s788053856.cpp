#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int n,k,m;
	cin >> n >> k;
	if(n%2==0) m=n/2;
	else m=(n+1)/2;
	if(k>m) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}