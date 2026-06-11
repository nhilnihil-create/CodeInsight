//http://drken1215.hatenablog.com/entry/2019/04/03/224800
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
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
signed main(void){
    int n; cin>>n;
    vector <int> a(n); 
    rep(i,n) cin>>a[i];
    int sum = accumulate(all(a),0);
    bitset <4000003> dp;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        dp |= (dp << a[i]);
    }
    
    long long res;
    for (res = (sum+1)/2; res < 4000003; ++res) {
        if (dp[res]) break;
    }
    cout << res << endl;
}
