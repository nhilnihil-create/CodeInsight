#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) (ll)((x).size())
#define rep(i,n) for(ll i=0;i<n;i++)
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}

int main(){
	string s; cin>>s;
	ll L=sz(s);
	//0 1 ...... L-1
	// 0 1 ... L-2
	ll ans=INF;
	rep(i,L-1){
		if(s[i]!=s[i+1]) chmin(ans,max(i+1,L-1-i));
	}
    cout<<(ans==INF?L:ans);
}