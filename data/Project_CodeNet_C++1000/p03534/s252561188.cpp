#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fr first
#define sc second
#define MAX ((ll)(1e18+100))
#define MOD ((ll)(1e9+7))
#define HSM ((ll)(307))
#define ARRS ((ll)(2e6+900))
#define pb push_back
#define mid ((l+r)>>1)
#define PI 3.14159265358979323846
#define MXN 500009
#define mep make_pair

ll a[400];
int main(){
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		a[s[i]]++;
	}
	ll k,p,c;
	k=a['a'];
	p=a['b'];
	c=a['c'];
	if(max({k,p,c})>min({k,p,c})+1){
		cout<<"NO";
	}
	else cout<<"YES";

}
