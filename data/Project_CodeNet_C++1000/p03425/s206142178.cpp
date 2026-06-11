#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define Graph vector<vector<ll>>
constexpr ll INF=(1ll<<60);
constexpr ll mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
	ll n;cin>>n;
	vector<ll> march(5);

	rep(i,n){
		string s;cin>>s;
		if(s[0]=='M') march[0]++;
		if(s[0]=='A') march[1]++;
		if(s[0]=='R') march[2]++;
		if(s[0]=='C') march[3]++;
		if(s[0]=='H') march[4]++;
	}

	ll ans=0;
	rep(i,(1<<5)){
		if(__builtin_popcount(i)!=3) continue;

		ll prd=1;
		rep(j,5){
			if((i>>j)&1){
				prd*=march[j];
			}
		}

		ans+=prd;
	}

	cout<<ans<<endl;
    return 0;
}