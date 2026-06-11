#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    if(A*B < N || A+B > N+1) {cout << -1 << endl; exit(0);};
    //now:=配置した中で最大の整数
    ll now = 0, rem = N-A;
    rep(i, A){
        //ここではx個階段状に並べる
        int x = min(B, rem+1);
        rem -= x-1;
        rep3(j, now+x, now+1){
            cout << j << endl;
        }
        now += x;
    }
}