#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll arr[405],prefs[405];
ll dp[405][405];
ll suminrange(ll l,ll r){
    if(l==0) return prefs[r];
    return prefs[r]-prefs[l-1];
}
ll findAns(ll l,ll r){
    if(l==r) return 0;
    if(dp[l][r]>=0) return dp[l][r];
    ll i,ans=LLONG_MAX;
    for(i=l;i<r;i++){
        ll myans = suminrange(l,i) + suminrange(i+1,r) + findAns(l,i) + findAns(i+1,r);
        ans = min(ans,myans);
    }
    return dp[l][r]=ans;
}
void solve(ll caseno){
	ll i,j,n,ans;
    cin>>n;
    mset(dp,-1);
    for(i=0;i<n;i++) cin>>arr[i];
    prefs[0]=arr[0];
    for(i=1;i<n;i++) prefs[i]=arr[i]+prefs[i-1];
    ans = findAns(0,n-1);
    cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
