#include <bits/stdc++.h>

#define int long long

using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007,INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int n;
 
signed main(){
	cin>>n;
	vint a(n),b(n);
	rep(i,0,n){
	    cin>>a[i];
	}
	rep(i,0,n){
	    cin>>b[i];
	}
	int res=0;
	rep(k,1,31){
	    int m=1<<k;
	    vint bb(n);
	    rep(i,0,n){
	        bb[i]=b[i]%m;
	    }
	    sort(all(bb));
	    int cnt=0;
	    rep(i,0,n){
	        int aa=a[i]%m;
	        cnt+=(lower_bound(all(bb),m-aa)-lower_bound(all(bb),m/2-aa))+(lower_bound(all(bb),2*m-aa)-lower_bound(all(bb),3*m/2-aa));
	    }
	    res|=(cnt%2)<<(k-1);
	}
	cout<<res<<endl;
	
	
	
	
	
	return 0;
}