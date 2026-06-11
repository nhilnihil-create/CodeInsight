#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	ll x=0,cnt=0;
	for(ll i=0;i<s.length();i++){
		if(s.substr(i,1)=="W"){
			cnt+=i-x;
			x++;
		}
	}
	cout<<cnt<<endl;
}
