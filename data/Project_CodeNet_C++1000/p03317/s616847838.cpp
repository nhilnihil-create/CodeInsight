#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define eps 1e-9
#define maxp 1000400
#define mod 1000000007
#define pi 3.141592653589793238
#define sin(s) scanf("%lld",&s);
#define sout(s) printf("%lld\n",s);
#define in(s) cin>>s
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define sp ' '
#define gear_change ios_base::sync_with_stdio(false),cin.tie(0)
#define nfl(i,n) for(i=0;i<n;i++)
#define sfl(i,s,e) for(i=s;i<e;i++)
#define ufl(i,n) for(i=n-1;i>=0;i--)
ll power(ll x,ll y){
    ll ret=1;
    while(y>0){
        if(y&1)
            ret=(ret*x);
        y/=2;
        x=(x*x);
    }
    return ret;
}
ll get(ll n){
	ll ret=0;
	while(n){
		ret+=n%10;
		n/=10;
	}
	return ret;
}
void solve(){
	ll n,k,i,pos=0;
	cin>>n>>k;
	vll vec(n);
	nfl(i,n){
		in(vec[i]);
		if(vec[i]==1){
			pos=i;
		}
	}
	if(n==1){
		cout<<0<<endl;
		return;
	}
	if(n==k){
		cout<<1<<endl;
		return;
	}
	ll ans=1;
	n-=k;
	k-=1;
	while(n>0){
		n-=k;
		ans++;
	}
	cout<<ans<<endl;
}	
int main(){
	gear_change;
	ll test=1;
	// in(test);
	while(test--){
		solve();
	}
}	
