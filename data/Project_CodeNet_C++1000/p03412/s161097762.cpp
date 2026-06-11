#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<int(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define show(x) cout<< #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int vx[]={0,0,-1,1};
int vy[]={1,-1,0,0};
int dx[]={1,0,-1,1,-1,1,0,-1};
int dy[]={1,1,1,0,0,-1,-1,-1};

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}	

const ll mod=1e9+7;
const int INF=INT_MAX/2;
const int N_MAX=100010;

int main(){
	int n;
	cin>>n;
	vector<ll> a(n),b(n);
	REP(i,n)cin>>a[i];
	REP(i,n)cin>>b[i];
	ll ans=0;
	for(int k=28;k>=0;k--){
		REP(i,n)a[i]=a[i]%(1<<(k+1));
		REP(i,n)b[i]=b[i]%(1<<(k+1));
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int cnt=0;
		REP(i,n){
			int T=1<<k;
			cnt+=lower_bound(b.begin(),b.end(),2*T-a[i])-
				lower_bound(b.begin(),b.end(),T-a[i]);
			cnt+=lower_bound(b.begin(),b.end(),(4*T-a[i]))-
				lower_bound(b.begin(),b.end(),(3*T-a[i]));
		}
		if(cnt%2)ans|=(1<<k);
	}
	cout<<ans<<endl;
	return 0;
}
