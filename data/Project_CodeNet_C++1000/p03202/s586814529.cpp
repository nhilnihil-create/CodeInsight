#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
const int INF=2012345678;
const ll LLINF=4012345678012345678LL;
const ll MOD=1000000007; //998244353; //
const ld PI=3.1415926535898;
const ld EPS=1e-9;
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(b==0)return a;return gcd(b,a%b);}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll expo(ll b,ll p,ll m){ll res=1; while(p){if(p&1)res=(res*b)%m; b=(b*b)%m; p>>=1;} return res;}
inline ll modinv(ll a,ll m){return expo(a,m-2,m);}

int n;
int arr[200005];
int x;
vector<ii> v;

bool carry(int i){
	if(i<=0)return 0;
	if(!v.empty()&&v.back().first==i){
		if(v.back().second==x-1){
			v.pop_back();
			if(!carry(i-1))return 0;
		}else{
			v[SZ(v)-1].second++;
		}
	}else{
		v.push_back(mp(i,1));
	}
	return 1;
}

inline bool poss(){
	v.clear();
	for(int i=1;i<n;i++){
		if(arr[i]<=arr[i-1]){
			if(x==1)return 0;
			while(!v.empty()&&v.back().first>arr[i])v.pop_back();
			if(v.empty())v.pb(mp(arr[i],1));
			else{
				if(v.back().first!=arr[i])v.pb(mp(arr[i],1));
				else if(v.back().second<x-1)v[SZ(v)-1].second++;
				else{
					v.pop_back();
					if(!carry(arr[i]-1))return 0;
				}
			}
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&arr[i]);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		x=mid;
		if(poss())r=mid;
		else l=mid+1;
	}
	printf("%d",l);
}
