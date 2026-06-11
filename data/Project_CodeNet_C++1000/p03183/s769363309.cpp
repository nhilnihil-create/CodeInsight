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

struct stats{
    ll w,s,v;
};

const int N=1e3+1, M=1e4+2;
vector<stats> a(N);
ll dp[N][M],n;

ll go(ll pos, ll left){
    if(pos==n) return 0;
    if(dp[pos][left]!=-1)
        return dp[pos][left];
    ll ans;
    if(left==M-1)
        ans=max(go(pos+1,left),a[pos].v+go(pos+1,a[pos].s));
    else{
        ans=go(pos+1,left);
        if(left>=a[pos].w)
            ans=max(ans,a[pos].v+go(pos+1,min(left-a[pos].w,a[pos].s)));
    }
    return dp[pos][left]=ans;
}

bool comp(stats a, stats b){
    return (a.s+a.w)>(b.s+b.w);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();

    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i].w>>a[i].s>>a[i].v;
    sort(a.begin(),a.end(),comp);
    //for(ll i=0;i<n;i++)
    //    cout<<a[i].w<<" "<<a[i].s<<" "<<a[i].v<<"\n";
    memset(dp,-1,sizeof(dp));
    cout<<go(0,M-1);



    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
