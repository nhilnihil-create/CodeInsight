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
    
    rep(i,n) {cin>>a[i]; if(a[i] == 0) {cout<<0<<endl; return 0;}};
    int ans = 114514;
    
    sort(a.begin(),a.end());
    map <int,int> ma;
    rep(i,n){
        ma[a[i]]++;
    }
    rep(i,13) if(ma[i]>=3) {cout<<0<<endl; return 0;}
    rep(i,n){
        if(i%2 == 0) a[i] = 24-a[i];
    }
    //rep(i,n) cout<<a[i]<<endl;
    a.push_back(0);
    rep(i,n+1) rep(j,n+1){
        if(i==j) continue;
        ans = min(ans, abs(a[i]-a[j]));
    }
    rep(i,n){
        ans = min(ans, min(a[i], 24-a[i]));
    }
    cout<<ans<<endl;
}
