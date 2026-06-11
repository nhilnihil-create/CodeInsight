#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>b(n);
    rep(i, 0, n)cin >> a[i];
    rep(i, 0, n)cin >> b[i];
    ll sum1=0, sum2=0;
    rep(i, 0, n){
        if(a[i]-b[i]>0)sum1 -= (a[i]-b[i]);
        else sum1 += (b[i]-a[i])/2;
    }
    if(sum1 >=0)cout << "Yes" << endl;
    else cout << "No" << endl;
}