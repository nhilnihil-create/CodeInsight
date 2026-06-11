#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int (i)=int (a);i<=int (b);i++)
#define F(i,a,b) for(int(i)=int (a);i>=int (b);i--)
#define pb push_back
#define ll long long
#define vt vector
int n,k;
ll a[1010];
ll s[1010];vt<ll> tmp;
vt<ll> v;
ll ans=0;
int main(){
	cin>>n>>k;
	f(i,1,n){
		cin>>a[i];s[i]=s[i-1]+a[i];
	}
	f(i,1,n){
		f(j,i,n){
			v.pb(s[j]-s[i-1]);
		}
	}
	F(i,40,0){
		tmp.clear();
		for(auto t:v){
			if(t >> i &1) tmp.pb(t);	
		}
		if(tmp.size()>=k){
			ans|=(1LL<<i);
			v.clear();v=tmp;
		}
	}cout<<ans;
}