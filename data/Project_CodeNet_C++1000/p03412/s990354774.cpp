#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    ll a[n],b[n];
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    ll ans=0;
    for(int d=32;d>=0;--d){
        rep(i,n)a[i]%=(1ll<<(d+1));
        rep(i,n)b[i]%=(1ll<<(d+1));
        sort(a,a+n);
        sort(b,b+n);
        ll cnt=0;
        ll cur=1LL<<d;
        rep(i,n){
            if(a[i]>=cur){
                cnt+=lower_bound(b, b+n, 2*cur-a[i])-b+n-(lower_bound(b, b+n, 3*cur-a[i])-b);
            }
            else cnt+=lower_bound(b, b+n,2*cur-a[i])-lower_bound(b, b+n,cur-a[i]);
        }
        ans+=(cnt%2)*(1LL<<d);
    }
    cout<<ans<<endl;
    return 0;
}