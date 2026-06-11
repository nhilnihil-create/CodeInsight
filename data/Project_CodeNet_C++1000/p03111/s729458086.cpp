#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int n, a, b, c, ans = 1000000000;
vector<int> l(10);
void solve(int now, int s1, int s2, int s3, int cnt){
    if(now == n){
        if(s1 == 0 || s2 == 0 || s3 == 0)return;
        cnt += abs(a-s1) + abs(b-s2) + abs(c-s3);
        chmin(ans, cnt);
    }else{
        solve(now+1, s1, s2, s3, cnt);
        solve(now+1, s1+l[now], s2, s3, cnt + 10 * (s1 != 0));
        solve(now+1, s1, s2+l[now], s3, cnt + 10 * (s2 != 0));
        solve(now+1, s1, s2, s3+l[now], cnt + 10 * (s3 != 0)); 
    }
}

int main() {
    cin >> n >> a >> b >> c;
    rep(i, n)cin >> l[i];
    solve(0, 0, 0, 0, 0);
    cout << ans << endl;
}
