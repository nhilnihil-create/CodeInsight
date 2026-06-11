#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	unordered_map<lli, lli> mp;
	rep(i, n){
		lli a;
		cin >> a;
		mp[a]++;
	}
	lli ans = 0;
	for(auto i : mp){
		if(i.first <= i.second) ans+=i.second-i.first;
		else ans+=i.second;
	}
	cout << ans << endl;
	return 0;
}
