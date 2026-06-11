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
	int n,k;
	string s;
	cin>>n>>k>>s;

	vi a;
	int tmp=1;
	if(s[0]=='0') a.pb(0);

	rep(i,n-1){
		if(s[i+1]!=s[i]){
			a.pb(tmp);
			tmp=1;
		}else{
			tmp++;
		}
	}
	a.pb(tmp);

	if(s[n-1]=='0') a.pb(0);

	int m=a.size();

	// rep(i,m) cout<<a[i]<<' ';
	// cout<<endl;


	vi sum(m+1);
	sum[0]=0;
	rep(i,m) sum[i+1]=sum[i]+a[i];

	// rep(i,m+1) cout<<sum[i]<<' ';
	// cout<<endl;

	int ans=0;

	if(2*k+1>=m+1){
		k=m/2;
	}

	for(int i=0;i+2*k+1<m+1;i+=2){
		chmax(ans,sum[i+2*k+1]-sum[i]);
	}

	
	cout<<ans<<endl;

	return 0;
}

