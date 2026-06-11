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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
	int n,m;cin>>n>>m;
	vector<pair<int,int>>t(m);
	rep(i,m){
		int a,b; cin>>a>>b;
		a--;
		b--;
		t[i]=mp(b,a);
	}
	int h=-1,ans=0;
	sort(all(t));
	rep(i,m){
		if(t[i].s>h){
			h=t[i].f-1;
			ans++;
		}
	}
	cout<<ans<<endl;
}

