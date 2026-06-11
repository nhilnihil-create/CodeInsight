// Jump, and you will find out how to unfold your wings as you fall.

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn],dp[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int H,W,n;cin>>H>>W>>n; swap(H,W);
    for(int i=0;i<n;i++){
	int x,y;cin>>x>>y;  swap(x,y);
	v[x].PB(y);
    }
    int ans=W;
    sort(v[1].begin(),v[1].end()); v[1].PB(W+1);
    for(int i=0;i<sz(v[1]);i++){
	if(i==0) dp[1].PB(1),ans=min(ans,v[1][0]-1);
	else dp[1].PB(v[1][i]);
    }
    for(int i=2;i<=H;i++){
	sort(v[i].begin(),v[i].end()); v[i].PB(W+1);
	int pt=0,st=0;
	for(int j=0;j<sz(v[i]);j++){
	    while(pt<sz(v[i-1]) && v[i-1][pt]<=st+1)
		++pt;
	    int num=v[i][j];
	    while(pt<sz(v[i-1]) && v[i-1][pt]<=v[i][j])
		num=min(num,(dp[i-1][pt]+1<v[i-1][pt] ? max(dp[i-1][pt]+1,st+1) : v[i][j]) ),++pt;
	    if(pt<sz(v[i-1]))
		num=min(num,(dp[i-1][pt]+1<v[i-1][pt] ? max(dp[i-1][pt]+1,st+1) : v[i][j]) );
	    dp[i].PB(num);
	    st=v[i][j];
	    if(num<st)
		ans=min(ans,st-1);
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
