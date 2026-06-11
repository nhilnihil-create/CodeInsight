#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

ll x,y,z,k;
vector<ll>a,b,c;

vector<ll>ra,rb,rc;

//値に対する二分探索

bool isOK(ll t){
    //ここに条件を満たすか判定する操作を書く
    ll s = 0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            ll now = a[i-1]+b[j-1];
            ll rem = t-now;
            ll l = lower_bound(c.begin(),c.end(),rem)-c.begin();
            s += (z-l);
        }
    }
    if(s>=k)return false;
    //ここまで
    return true;
}

ll binary_search(){
    ll ng = 0;
    ll ok = 1e18;

    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        if(isOK(mid))ok=mid;
        else ng=mid;
    }
    return ng;
}

int main(){
    cin >> x >> y >> z >> k;
    a.resize(x);
    b.resize(y);
    c.resize(z);
    rep(i,x)cin>>a[i];
    rep(i,y)cin>>b[i];
    rep(i,z)cin>>c[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.begin(),c.end());
    ra.resize(x+1,0);
    rb.resize(y+1,0);
    rc.resize(z+1,0);
    rep(i,x)ra[i+1]=ra[i]+a[i];
    rep(i,y)rb[i+1]=rb[i]+b[i];
    rep(i,z)rc[i+1]=rc[i]+c[i];
    ll shikiri =  binary_search();
    reverse(c.begin(),c.end());
    vector<ll>ans;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(ans.size()>k)continue;
            for(int p = 0;p<z;p++){
                if(a[i]+b[j]+c[p]>shikiri){
                    ans.push_back(a[i]+b[j]+c[p]);
                }
                else{
                    break;
                }
            }
        }
    }
    sort(ans.rbegin(),ans.rend());
    while(ans.size()<k)ans.push_back(shikiri);
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}

