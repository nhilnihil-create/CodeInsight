#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

const int N=1e5+1;
ll dp[N][3],n;
vector<ll> a(N),b(N),c(N);

ll go(ll pos, ll prev){
    if(pos==n) return 0;
    if(dp[pos][prev]!=-1)
        return dp[pos][prev];
    ll ans=0;
    if(prev!=0) ans=max(ans,a[pos]+go(pos+1,0));
    if(prev!=1) ans=max(ans,b[pos]+go(pos+1,1));
    if(prev!=2) ans=max(ans,c[pos]+go(pos+1,2));
    return dp[pos][prev]=ans;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i]>>b[i]>>c[i];
    memset(dp,-1,sizeof(dp));
    cout<<go(0,3);


    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}