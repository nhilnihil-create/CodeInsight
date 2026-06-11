#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;

template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}

int main(){
	//input
	ll N; cin>>N;
	vector<ll> D(N);
	rep(i,N) cin>>D[i];
	vector<ll> d(13,0);
	d[0]=1;
	vector<ll> ans(25,0);
	bool right=true;

	//solve
	rep(i,N){
		d[D[i]]++;
	}
	rep(i,13){
		if(((i==0 || i==12) && d[i]>=2) || d[i]>=3){
			cout<<0;
			return 0;
		}
		else if(d[i]==2){
			ans[i]=1;
			ans[24-i]=1;
		}
		else if(d[i]==1){
			if(right){
				right=false;
				ans[i]=1;
			}
			else{
				right=true;
				ans[24-i]=1;
			}
		}
	}
	ans[24]=ans[0];

	ll mem=INF,ANS=24;
	rep(i,25){
		if(ans[i]==1){
			chmin(ANS,abs(mem-i));
			mem=i;
		}
	}

	cout<<ANS;
}