#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define loop(k) rep(author_is_masa,k)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/

signed main(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	if(s[0]!=t[0]){
		cout<<-1<<endl;
		return 0;
	}

	int l=n/gcd(n,m)*m;
	vi sv(n),tv(m);
	vector<tuple<int,int,int>> x;
	rep(i,n){
		x.pb(make_tuple(i*l/n,0,i));
	}
	rep(i,m){
		x.pb(make_tuple(i*l/m,1,i));
	}
	sort(all(x));
	int ok=1;
	rep(i,n+m-1){
		auto p=x[i-1];
		auto q=x[i];
		if(get<0>(p)==get<0>(q)){
			int a=get<2>(p);
			int b=get<2>(q);
			if(s[a]!=t[b]) ok=0;
		}
	}

	if(ok){
		cout<<l<<endl;
	}else{
		cout<<-1<<endl;
	}

	return 0;
}

