#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m = 1e9+7;

int main() {
	string s; cin>>s;
	vector<ll> ABC(s.size()+1), AB(s.size()+1), A(s.size()+1);
	ll qmarks=1;

	for (ll i=0; i<s.size(); i++) {
		A[i+1] = A[i];
		AB[i+1] = AB[i];
		ABC[i+1] = ABC[i];
		if (s[i]=='A')
			A[i+1] = (A[i]%m + qmarks%m)%m;
		if (s[i]=='B')
			AB[i+1] = (AB[i]%m + A[i]%m)%m;
		if (s[i]=='C')
			ABC[i+1] = (ABC[i]%m + AB[i]%m)%m;
		if (s[i]=='?') {
			A[i+1] = ((A[i]*3)%m + qmarks%m)%m;
			AB[i+1] = ((AB[i]*3)%m + A[i]%m)%m; 
			ABC[i+1] = ((ABC[i]*3)%m + AB[i]%m)%m;
			qmarks = (qmarks*3)%m;
		}
	}
	
	cout << ABC.back() << endl;

	return 0;
}
