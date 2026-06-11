#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
int inf=1000001000;
ll INF=100000000000000000;


int main() {
    ll n,c;
    cin >> n >> c;
    vector<pair<ll,ll>> a(n);
    rep(i,n){
        ll f,g;
        cin >> f >> g;
        a[i].first=f;a[i].second=g;
    }
    vector<ll> aa(n,0),bb(n+1,0);
    ll l=0,o=0,now=0;
    rep(i,n){
        o+=a[i].second-a[i].first+l;
        l=a[i].first;
        now=max(now,o);
        aa[i]=now;
    }
    l=c,o=0,now=0;
    rep(i,n){
        o+=a[n-i-1].second-l+a[n-i-1].first;
        l=a[n-i-1].first;
        now=max(now,o);
        bb[n-i-1]=now;
    }
    ll ans=max(aa[n-1],bb[0]);
    rep(i,n){
        ll f=a[i].first,g=a[i].second;
        if (f>c/2) break;
        ans=max(ans,aa[i]-f+bb[i+1]);
    }
    rep(i,n){
        ll f=c-a[n-i-1].first,g=a[n-i-1].second;
        if (f>c/2) break;
        ll k;
        if (n-i-2<0) k=0;
        else k=aa[n-i-2];
        ans=max(ans,bb[n-i-1]-f+k);
    }
    cout << ans << endl;
}

