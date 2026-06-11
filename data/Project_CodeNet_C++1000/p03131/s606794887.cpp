#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
void solve(){
	ll k,a,b;
	cin>>k>>a>>b;
	if(b-a<=2)
	cout<<k+1;
	else{
		if(k<=a-1)
		cout<<k+1;
		else
		cout<<a+((k-a+1)/2)*(b-a)+(k-a+1)%2;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++)
	solve();
}
