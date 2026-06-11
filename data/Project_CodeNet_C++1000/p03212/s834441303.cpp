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

ll n;
ll cnt = 0;

void dfs(ll x, bool f1, bool f2, bool f3){
    if(x > n) return;
    if(f1&&f2&&f3)cnt++;
    dfs(x*10+3, true, f2, f3);
    dfs(x*10+5, f1, true, f3);
    dfs(x*10+7, f1, f2, true);
}

int main(){
    cin >> n;
    dfs(0, 0, 0, 0);
    cout << cnt << endl;
}