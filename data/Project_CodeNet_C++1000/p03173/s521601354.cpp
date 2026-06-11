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

const int N=401;
ll dp[N][N],n;
vector<ll> a(N),pref(N);

ll go(int l, int r){
    if(l==r) return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    ll ans=MAX,srange=pref[r]-(l>0?pref[l-1]:0);
    for(int i=l;i<r;i++)
        ans=min(ans,srange+go(l,i)+go(i+1,r));
    return dp[l][r]=ans;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n;i++)
        cin>>a[i];
    pref[0]=a[0];
    for(int i=1;i<n;i++)
        pref[i]=pref[i-1]+a[i];
    cout<<go(0,n-1);

    

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}