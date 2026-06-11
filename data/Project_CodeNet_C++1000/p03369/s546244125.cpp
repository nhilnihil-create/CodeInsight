#include<bits/stdc++.h>
#define ll long long int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin>>s;
	ll l=s.size();
	ll z=0;
	for(ll i=0; i<l; i++){
		if(s[i]=='o')
			z++;
	}
	ll x=700;
	cout<<x+(z*100);
}