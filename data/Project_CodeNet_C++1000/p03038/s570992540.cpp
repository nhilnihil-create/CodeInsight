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
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main() {
    int n, m;
    cin >> n >> m;
    vector<ll>a(n);
    vector<pll>b(m);
    ll sum = 0;
    rep(i, 0, n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    rep(i, 0, m)cin >> b[i].second >> b[i].first;
    sort(b.begin(),b.end(),greater<pll>());
    int j = 0,t = 0;
    rep(i, 0, n){
        if(i+1>b[j].second+t){
            t += b[j].second;
            j++;
        }
        if(j == m){
            sum += a[i];
            continue;
        }
        sum += max(a[i],b[j].first); 
    }
    cout << sum << endl;
}