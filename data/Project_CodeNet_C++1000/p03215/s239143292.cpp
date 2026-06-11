#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    a[0]=0;
    multiset<ll> ms;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            ms.insert(a[i]-a[j]);
        }
    }
    multiset<ll> ::iterator itr,i1,i2;
    ll now;
    itr=ms.end();
    itr--;
    for(ll i=0LL;;i++){
        if((1LL<<i)<=*itr)now=(1LL<<i);
        else break;
    }
    multiset<ll> tmp;
    ll maki=now;
    while(maki){
        i1=ms.lower_bound(now);
        i2=ms.lower_bound(now+maki);
        if(distance(i1,i2)>=k){
            maki>>=1;
            now+=maki; 
        }
        else{
            tmp.clear();
            for(itr=i1;itr!=i2;itr++){
                tmp.insert(*itr);
            }
            for(itr=tmp.begin();itr!=tmp.end();itr++){
                ms.erase(*itr);
                ms.insert(*itr-maki);
            }
            maki>>=1;
            now-=maki;
            if(!maki)now--;
        }
    }
    cout <<now<<endl;
    return 0;
}
