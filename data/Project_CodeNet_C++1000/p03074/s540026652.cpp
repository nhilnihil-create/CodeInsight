#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,k;
	string s;
	cin >> n >> k >> s;

	vector<int> B(0);
	char c;
	for(int i=0; i<n; i++){
		if(s[i]!=c){
			B.push_back(i);
			c = s[i];
		}
	}

	int m = B.size();
	for(int i=0; i<=2*k; i++) B.push_back(n);

	int ans = 0;
	for(int i=0; i<m; i++){
		if(s[B[i]]=='0') ans = max(ans,B[i+2*k]-B[i]);
		else ans = max(ans,B[i+2*k+1]-B[i]);
	}
	cout << ans << endl;

	return 0;
}