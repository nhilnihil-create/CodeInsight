#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    ll n,h,w;
    cin>>n>>h>>w;
    int ans=0;
    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        if(a>=h&&b>=w)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
