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
	ll n,m;cin>>n>>m;

	if(n==1 && m==1) cout<<1<<endl;
	else if(n==1 || m==1) cout<<max(n-2,m-2)<<endl;
	else cout<<(n-2)*(m-2)<<endl;

    return 0;
}