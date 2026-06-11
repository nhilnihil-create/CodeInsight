#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
#define era(t) t.erase(unique(be(t)),t.end())
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
typedef long long ll;
using namespace std;
const ll mod=1000000007,mod9=1000000009;
template <class T>inline T lcm(T a,T b){return (a*b/__gcd(a,b));}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a[n],b[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(i){
            b[i]=a[i]+b[i-1];
        }
        else{
            b[i]=a[i];
        }
    }
    ll ans=1e18;
    ll index1=0,index3=2;
    for(ll i=1;i<n-2;i++){
        ll ma,mi;
        ll x,y,z;
        while(abs(b[index1+1]*2-b[i])<abs(b[index1]*2-b[i])){
            index1++;
        }
        while(abs(b[n-1]-2*b[index3+1]+b[i])<abs(b[n-1]-2*b[index3]+b[i])){
            index3++;
        }
        x=b[i]-b[index1];
        y=b[index3]-b[i];
        z=b[n-1]-b[index3];
        ma=max(x,max(y,max(z,b[index1])));
        mi=min(x,min(y,min(z,b[index1])));
        ans=min(ans,ma-mi);
    }
    cout << ans<<endl;
    return 0;
}
