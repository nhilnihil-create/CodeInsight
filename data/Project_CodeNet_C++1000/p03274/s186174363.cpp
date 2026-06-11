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
    int n, k;
    cin >> n >> k;
    vector<ll>plus, minus;
    rep(i, 0, n){
        int a;
        cin >> a;
        if(a>=0)plus.push_back(a);
        else minus.push_back(a);
    }
    reverse(minus.begin(),minus.end());
    int p = plus.size();
    int q = minus.size();
    ll ans = inf;
    rep(i, 0, k+1){
        int cnt = 0;
        ll temp = 0;
        if(i>p || k-i >q)continue;
        if(i!=0)temp += plus[i-1], cnt++;
        if(i!=k)temp += -1*(minus[k-i-1]), cnt++;
        if(cnt == 2)temp+= min(plus[i-1], -1*(minus[k-i-1]));
        //cout << i <<  " "<<temp << " " << plus[i-1] << " " <<  -1*(minus[k-i-1]) << endl;
        ans = min(ans, temp);
    }
    cout << ans << endl;
}