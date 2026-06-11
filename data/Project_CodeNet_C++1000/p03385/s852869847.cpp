//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
string s;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	map<char,ll> mp;
	cin>>s;
	for(char ch:s)
	++mp[ch];
	if(mp['a']==1&&mp['b']==1&&mp['c']==1)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}
