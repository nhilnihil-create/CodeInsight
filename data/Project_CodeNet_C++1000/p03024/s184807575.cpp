#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	string s;
	cin>>s;
	ll ans=15-s.size();
	for(ll i=0;i<s.size();i++){
		if(s[i]=='o'){
			ans++;
		}
	}
	cout << (ans>=8?"YES":"NO");
	// your code goes here
	return 0;
}