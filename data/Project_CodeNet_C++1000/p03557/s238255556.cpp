
#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n),b(n),c(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    rep(i,0,n)cin>>c[i];

    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    
    ll ans=0;
    rep(i,0,n){
        auto num = lower_bound(a.begin(),a.end(),b[i])-a.begin();
        auto num1 = n - (upper_bound(c.begin(),c.end(),b[i])-c.begin());
        ans+=num*num1;
    }
    cout<<ans<<endl;

    return 0;
}

