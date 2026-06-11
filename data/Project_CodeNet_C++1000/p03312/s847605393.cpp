#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define mod 1000000007LL
#define FOR(i,m,n) for(int i = (m); i < (n); i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())
 
 
typedef long long ll;
typedef vector<int> vi; 
typedef pair<int,int> ii;

ll power(ll a, ll b){
    int ans = 1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
 

int main(){
	fastio;

    int n; cin>>n;
    vector<ll> v(n);
    vector<ll> p(n);
    FOR(i,0,n) cin>>v[i];
    p[0]=v[0];
    FOR(i,1,n) p[i]=p[i-1]+v[i];
    
    
    int x, y, z;
    ll ans, ans_=1e15;
    FOR(i,1,n-2){
        int pos=lower_bound(all(p),(p[i]+1)/2)-p.begin();
        if(pos-1>=0 && abs(2LL*p[pos]-p[i])>abs(2LL*p[pos-1]-p[i])) x=pos-1;
        else x=pos;
        pos=lower_bound(all(p), p[i]+(p[n-1]-p[i]+1)/2)-p.begin();
        ll xd=p[pos]-p[i], xdd=p[pos-1]-p[i];
        if(pos-1> i && abs(xd-p[n-1]+p[pos])>abs(xdd-p[n-1]+p[pos-1])) z=pos-1;
        else z=pos;
        
        ll sum1=p[x], sum2=p[i]-p[x], sum3=p[z]-p[i] ,sum4=p[n-1]-p[z];
        ans=max({abs(sum1-sum2), abs(sum1-sum3), abs(sum1-sum4), abs(sum2-sum3), abs(sum2-sum4), abs(sum3-sum4)});
        // cout<<"ans="<<ans<<endl;
        // cout<<x<<" "<<i<<" "<<z<<endl;
        ans_=min(ans, ans_);
    }

    cout<<ans_<<endl;

	return 0;
}