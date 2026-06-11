#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	vector<int> L(n+1);
	vector<int> R(n+1);

	L[0] = 0;
	R[n] = 0;

	for(int i=0; i<n; i++) L[i+1] = __gcd(L[i],a[i]);
	for(int i=n-1; i>=0; i--) R[i] = __gcd(R[i+1],a[i]);
	
	vector<int> M(n);
	for(int i=0; i<n; i++) M[i] = __gcd(L[i],R[i+1]);

	cout << *max_element(M.begin(), M.end()) << endl;

}