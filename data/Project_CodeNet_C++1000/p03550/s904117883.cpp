#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
const long long INF = 1LL << 60;
const int MOD = 1000000007;
signed main(void){
    int n,z,w; cin>>n>>z>>w;
    vector <int> a(n); 
    rep(i,n) cin>>a[i];
    if(n==1) {cout<<abs(a[0]-w)<<endl; return 0;}
    else cout<<max(abs(a[n-1]-w), abs(a[n-2]-a[n-1]))<<endl;
}
