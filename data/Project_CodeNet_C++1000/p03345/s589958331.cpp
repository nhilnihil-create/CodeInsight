#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	ll a,b,c,k; cin>>a>>b>>c>>k;
	rep(i,k){
		ll ta, tb,tc;
		ta=b+c; tb=a+c; tc=a+b;
		a=ta; b=tb; c=tc;
	}
	if(a-b>1e18) cout<<"Unfair"<<endl;
	else cout<<a-b<<endl;
}