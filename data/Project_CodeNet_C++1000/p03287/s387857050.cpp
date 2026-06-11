#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const ll INF=2e15;
const double PI=acos(-1);


vector<pair<ll,int>> vectorCnt(vector<ll> a) {
    sort(a.begin(),a.end());
    int n=a.size();
    vector<pair<ll,int>> b;
    int cnt=1;
    rep(i,n-1) {
            if (a[i+1]!=a[i]) {
                b.push_back(make_pair(a[i],cnt));
                cnt=1;
            } else {
                ++cnt;
            }
    }
    b.push_back(make_pair(a[n-1],cnt));
    return b;
}


int main() {
    ios_base::sync_with_stdio(false); 

    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1);
    ll ans=0;
    rep(i,n) cin >> a[i+1];
    rep(i,n) {
        a[i+1]+=a[i];
        a[i+1]=a[i+1]%m;
    }
    vector<pair<ll,int>> b=vectorCnt(a);
    rep(i,b.size()) {
        ll cnt=b[i].second;
        ans+=cnt*(cnt-1)/2;
    }
    cout << ans << endl;

    return 0;
}
