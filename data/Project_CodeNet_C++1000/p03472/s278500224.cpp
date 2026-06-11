//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    ll n,h,ans=0; cin>>n>>h;
    vector<ll> a(n,0),b(n,0);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    sort(al(a)); reverse(al(a));
    sort(al(b)); reverse(al(b));
    ll i=0;
    while(b[i]>a[0] && i<n){
            h-=b[i];
            ans++;
            i++;
            if(h<=0) break;
    }
        if(h>0){
            ans+=(h+a[0]-1)/a[0];
            h=0;
    }
    cout<<ans<<endl;
}
