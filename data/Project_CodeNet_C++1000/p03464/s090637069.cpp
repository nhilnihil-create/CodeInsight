#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i, 0, n)cin >> a[i];
    reverse(a.begin(),a.end());
    ll mx = 3, mn = 2;
    if(a[0]!=2){
        cout << -1 << endl;
        return 0;
    }
    rep(i, 0, n){
        mn = (mn+a[i]-1)/a[i]*a[i];
        mx = (mx+a[i]-1)/a[i]*a[i];
        //cout << mn << " " << mx << endl;
    }
    if(mn==mx){
        cout << -1 << endl;
        return 0;
    }else cout << mn << " " << mx-1 << endl;
}