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
	string s;
	cin>>s;

	vi black(n+1,0);
	// [i]=#Black(s[0]-s[i-1])  [0]=-1,[n]=sum
	
	rep(i,n){
		black[i+1]=black[i]+(s[i]=='#');
	}
	int ans=INF;

	rep(i,n){
		int b=black[i];
		int w=(n-1-i)-(black[n]-black[i+1]);
		chmin(ans,b+w);
	}
	cout<<ans<<endl;


	return 0;
}
