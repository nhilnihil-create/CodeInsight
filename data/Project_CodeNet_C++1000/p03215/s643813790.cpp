#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define all(t) (t).begin(),(t).end()
#define MOD 1000000007
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}

int main(){
	
	ll n,k;
	cin >> n >> k;
	ll a[1010],sum[1010];
	sum[0]=0;
	FOR(i,n){
		cin >> a[i];
		
		sum[i+1]=sum[i]+a[i];
	}
	vector<ll> v;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			v.push_back(sum[j+1]-sum[i]);
		}
	}

	for(int i=40;i>=0;i--){
		vector<ll> a;
		FOR(j,(int)v.size()){
			if(1ll<<i & v[j])a.push_back(v[j]);
		}
		if(k<=(int)a.size()){
			v=a;
		}
	}
	ll ans=(1ll<<41)-1;
	FOR(i,(int)v.size()){
		ans&=v[i];
	}

	cout << ans << endl;

}