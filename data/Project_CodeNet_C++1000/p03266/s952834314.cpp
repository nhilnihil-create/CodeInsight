#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n ; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x) // decltypeで型取得、引数があればva_argsのところに入れる
using namespace std;
typedef long long ll; // long longをllでかけるようにした
const int INF = 1e9;
const int MOD = 1000000007; // 計算してからmodで割る ans = (ans * a) % mod
#define int long long
template <typename T = long long > T in () { T x; cin >> x; return(x);}
// int a = in() のように使うlong long以外の型の時はstirng s = in<string>()のように型を指定する


signed main(void){
    int n, k; cin >> n >> k;
    int cnt = 0, ans;
    for(int i = 1; i <= n; i++){
        if(i % k == 0) cnt++;
    }
    ans = pow(cnt, 3);
    if(k % 2 == 0){// k偶数
        cnt = 0;
        for(int i = 1; i <= n; i++){
            if(i % k == (k / 2)) cnt++;
        }
        ans += pow(cnt, 3);
    }
    cout << ans << endl;
}