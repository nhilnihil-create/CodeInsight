#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz size()
#define pb push_back 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define mp(x,y) make_pair(x,y)
const ll MOD=1000000007;
const ll INF=1000000000000000;

vector<ll> pw2(51,1); vector<ll> pw10(19,1);
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll mid(ll x,ll y,ll z){return x>y?y>=z?y:min(z,x):x>=z?x:min(y,z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll myceil(ll x,ll y){if(x<=y) return 1;else if(x%y==0) return x/y;else return x/y+1;}
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
vector<ll> divisor(ll x){vector<ll> div;
	for(ll i=1;i*i<=x;i++){if(x%i==0){div.pb(i);if(i*i!=x)div.pb(x/i);}}
	sort(div.bg,div.ed);return div;}

int main(){
	ll A,B,C; cin>>A>>B>>C;
	if(C==mid(A,B,C)) cout<<"Yes";
	else cout<<"No";    
}