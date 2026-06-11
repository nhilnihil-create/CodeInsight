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
	vector<int> l(n+1),r(n+1);
	REP(i,n)cin>>l[i]>>r[i];
	l[n]=r[n]=0;
	sort(l.begin(),l.end(),greater<int>());
	sort(r.begin(),r.end());
	ll ans=0;
	REP(i,n+1){
		if(l[i]>r[i])ans+=2*(l[i]-r[i]);
	}
	cout<<ans<<endl;
	return 0;
}
