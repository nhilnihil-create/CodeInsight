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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k; cin>>n>>k;
    vector <pair<int,int>> p(100010);
    rep(i,n){
        int a,b; cin>>a>>b;
        p[i] = {b,a};
    }
    sort(p.begin(),p.end(),greater<pair <int,int>>());
    
    stack <pair <int,int>> stk;
    vector <int> cnt(100100);
    int x = 0;
    int ans = 0, d = 0;
    for(int i=0;i<k;i++){
        d += p[i].F;
        cnt[p[i].S-1]++;
        if(cnt[p[i].S-1] == 1) x++;
        else stk.push({p[i].F,p[i].S});
    }
    ans = x*x + d; 
    for(int i=k;i<n;i++){
        if(cnt[p[i].S-1]) continue;
        if(stk.size()== 0) break; 
        auto tmp = stk.top(); stk.pop();
        if(cnt[tmp.S-1]==1) continue;
        x++;
        d += p[i].F; d -= tmp.F;
        cnt[tmp.S-1]--;
        cnt[p[i].S-1]++;
        chmax(ans, x*x + d);
    }
    cout<<ans<<endl;
}
