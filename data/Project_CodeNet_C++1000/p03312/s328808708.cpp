#define _USE_MA_DEFINES
#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define inf (1ll<<60)
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())

using namespace std;

const int mod=1e9+7;

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

void run(){
    int n;
    cin>>n;
    vi a(n+1);
    rep(i,n){
        cin>>a[i+1];
        a[i+1]+=a[i];
    }
    int ans=inf;
    REP(i,2,n-2){
        int l=upper_bound(all(a),a[i]/2)-a.begin();
        int r=upper_bound(all(a),(a[n]-a[i])/2+a[i])-a.begin();
        REP(j,-1,1){
            REP(k,-1,1){
                int P=a[l+j],Q=a[i]-P,R=a[r+k]-a[i],S=a[n]-a[i]-R;
                ans=min(ans,max({P,Q,R,S})-min({P,Q,R,S}));
            }
        }
    }
    cout<<ans<<endl;
}
        