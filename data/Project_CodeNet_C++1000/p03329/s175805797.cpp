#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
using graph = vector<vector<int>>;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define all(x) (x).begin(),(x).end()
#define size(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000

#define pb push_back
#define mp make_pair
#define f first
#define s second

template<class T> inline bool chmax(T &a,T b) { if (a<b) { a=b; return true; } return false; }
template<class T> inline bool chmin(T &a,T b) { if (b<a) { a=b; return true; } return false; }

vector<ll> dp(200000);

int main(){
	int n;cin>>n;
	dp.assign(200000,INF);
	vector<ll>v(0);
	int i=0,j=1;
	while(pow(6,i)<100000){
		v.pb(pow(6,i));
		i++;
	}
	while(pow(9,j)<100000){
		v.pb(pow(9,j));
		j++;
	}
	i=0;
	dp[0]=0;
	while(i<100000){
		for(auto&x:v){
			if(i+x>100000)continue;
			chmin(dp[i+x],dp[i]+1);
		}
		i++;
	}
	cout<<dp[n]<<endl;
}
