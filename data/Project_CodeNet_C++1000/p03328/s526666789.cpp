#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define eps 1e-9
#define maxp 100000000000000000000
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
#define nl '\n'
#define sp ' '
#define gear_change ios_base::sync_with_stdio(false),cin.tie(0)
#define nfl(i,n) for(i=0;i<n;i++)
#define sfl(i,s,e) for(i=s;i<e;i++)
#define ufl(i,n) for(i=n-1;i>=0;i--)
ll get(ll n){
	return (n*(n+1))/2;
}
void solve(){
	ll a,b,i;
	cin>>a>>b;
	for(i=1;i<1000;i++){
		ll sum=get(i);
		ll sum2=get(i+1);
		if(sum-a==sum2-b){
			cout<<sum-a<<endl;
			return;
		}
	}
}	
int main(){
	gear_change;
	ll test=1;
	// in(test);
	while(test--){
		solve();
	}
}	
