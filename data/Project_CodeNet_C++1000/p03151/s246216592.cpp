#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
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
	int n;cin>>n;
	vi a(n),b(n);
	rep(i,n)cin>>a[i];
	rep(i,n)cin>>b[i];

	int suma=0,sumb=0;
	rep(i,n)suma+=a[i];
	rep(i,n)sumb+=b[i];
	if(suma<sumb){
		cout<<-1<<endl;
		return 0;
	}

	vi x;
	int ans=0;
	int diff=0;
	rep(i,n){
		if(a[i]>b[i]) x.pb(a[i]-b[i]);
		if(a[i]<b[i]){
			ans++;
			diff+=b[i]-a[i];
		}
	}
	sort(allr(x));

	int i=0;

	while(diff>0){
		diff-=x[i];i++;
		ans++;
	}
	cout<<ans<<endl;


	return 0;


}
