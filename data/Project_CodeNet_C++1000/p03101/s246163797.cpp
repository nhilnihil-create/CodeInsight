#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int h,w;
    cin >> h >> w;
    int ans = h*w;
    int h2,w2;
    cin >> h2 >> w2;
    ans -= (h2*w + w2*h - h2*w2);
    cout << ans << endl;
    return 0;
}

/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/