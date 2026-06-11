#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	string s;
	cin >> n >> q >> s;

	vector<int> t(n+1,0);
	for(int i=0; i<n; i++) t[i+1] = t[i]+((s[i]=='A'&&s[i+1]=='C')?1:0);
	
	for(int i=0; i<q; i++){
		int l,r;
		cin >> l >> r;
		cout << t[r-1]-t[l-1] << endl;
	}

	return 0;
}