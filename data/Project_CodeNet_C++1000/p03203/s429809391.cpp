#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/





int H, W, N, X[201010], Y[201010];
vector<int> rows[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> H >> W >> N;
    swap(H, W);
    rep(i, 0, N) cin >> X[i] >> Y[i];
    rep(i, 0, N) rows[Y[i]].push_back(X[i]);
    rep(y, 0, H + 1) sort(all(rows[y]));

    int ans = W;
    int cx = 1;
    rep(cy, 1, H + 1) {
        int mi = W;
        fore(x, rows[cy]) if (cx < x) chmin(mi, x - 1);
        chmin(ans, mi);
        
        cx++;
        fore(x, rows[cy + 1]) {
            if (x < cx) continue;
            else if (x == cx) cx++;
            else if (cx < x) break;
        }
    }
    cout << ans << endl;
}