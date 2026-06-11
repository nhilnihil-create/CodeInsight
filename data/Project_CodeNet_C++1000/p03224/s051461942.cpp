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



int N;
vector<int> ans[1010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;

    int K = -1;
    rep(k, 2, 1010) if (k * (k - 1) / 2 == N) K = k;
    if (K < 0) {
        printf("No\n");
        return;
    }

    int x = 1;
    rep(a, 0, K) rep(b, a + 1, K) {
        ans[a].push_back(x);
        ans[b].push_back(x);
        x++;
    }

    printf("Yes\n%d\n", K);
    rep(k, 0, K) {
        printf("%d", ans[k].size());
        fore(i, ans[k]) printf(" %d", i);
        printf("\n");
    }
}