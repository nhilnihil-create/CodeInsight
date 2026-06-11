#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1 LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

auto GCD(auto a, auto b) { //ユークリッドの互助法で最大公約数
    if(a % b == 0)return b;
    else return GCD(b, a % b);
}
auto LCM(auto a, auto b) { //GCDを使って最小公倍数を求める
    auto g = GCD(a, b);
    return (a / g) * b;
}


int main() {
    LL N,M;cin >> N >> M;
    string S,T;cin >> S >> T;
    LL g = LCM(N,M);

    map<LL,char> m;
    map<LL,int> c;
    bool ok = true;
    int s = g/N;
    rep(i,N){
        m[i*s] = S[i];
        c[i*s]++;
    }
    int t = g/M;
    rep(i,M){
        if(m[i*t] != T[i] && c[i*t] > 0){
            ok = false;
        }
    }

    if(ok)cout << g << endl;
    else cout << -1 << endl;
}