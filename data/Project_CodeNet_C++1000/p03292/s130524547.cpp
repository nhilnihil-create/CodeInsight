#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define eps 1e-9
#define maxp 99940000
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
string rot(string s){
	string ret="";
	ll i;
	for(i=1;s[i];i++){
		ret+=s[i];
	}
	ret+=s[0];
	return ret;
}
void solve(){
	ll arr[3]={0};
	ll a,b,c;
	cin>>a>>b>>c;
	arr[0]=abs(a-b);
	arr[1]=abs(b-c);
	arr[2]=abs(c-a);
	sort(arr,arr+3);
	cout<<arr[0]+arr[1]<<endl;
}	
int main(){
	gear_change;
	ll test=1;
	// in(test);
	while(test--){
		solve();
	}
}	
