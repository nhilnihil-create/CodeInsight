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

const int maxn=5010,mod=1e9+7;
const ll inf=1e18;

int dp1[maxn][maxn],dp2[maxn][maxn],a[maxn];
ll ans[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,A,B;cin>>n>>A>>B;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    a[n+1]=n+1;
    for(int i=0;i<=n+1;i++){
	for(int j=i+1;j<=n+1;j++){
	    dp1[i][j]=dp1[i][j-1]+(a[i]>a[j]);
	}
    }
    for(int j=n+1;j>=0;j--){
	for(int i=j-1;i>=0;i--){
	    dp2[i][j]=dp2[i+1][j]+(a[i]>a[j]);
	}
    }
    for(int r=1;r<=n+1;r++){
	ans[r]=inf;
	for(int l=0;l<r;l++){
	    if(a[l]>a[r] || dp1[l][r-1]+dp2[l+1][r]!=r-l-1) continue;
	    ans[r]=min(ans[r],ans[l]+1ll*A*dp2[l+1][r]+1ll*B*dp1[l][r-1]);
	}
    }
    return cout<<ans[n+1]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.
