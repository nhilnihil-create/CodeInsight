#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
signed main(void){
    int n; cin>>n;
    vector <int> a(n); 
    rep(i,n) cin>>a[i];
    auto ima = max_element(all(a));
    auto imi = min_element(all(a));
    int ma = *ima, mi = *imi;
    bool pom;
    cout<<2*n-1<<endl;
    int x;
    if(abs(ma)>=abs(mi)) pom=true , x = (ima - a.begin()); else pom = false, x = imi - a.begin();
    rep(i,n) {if(pom) a[i]+= ma; else a[i]-=mi; cout<<x+1<<' '<<i+1<<endl;}
    //rep(i,n) cout<<a[i]<<endl;
    if(pom) rep(i,n-1) cout<<i+1<<' '<<i+2<<endl;
    else rrep(i,n-1) cout<<i+2<<' '<<i+1<<endl;
}
