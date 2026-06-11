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

int main(){
    int n;
    cin >> n;
    ll sum = 0; 
    vector<pair<ll,pair<ll, ll>>>a(n);
    rep(i, 0, n){
        ll p, q;
        cin >> p >> q;
        a[i].first = p+q;
        a[i].second.first = p;
        a[i].second.second = q;
        sum -= q;
    }
    sort(a.begin(),a.end(),greater<pair<ll,pair<ll, ll>>>());
    
    for(int i = 0; i <n; i+=2){
        sum += a[i].first;
    }
    cout << sum << endl;
}