#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    cin >> N;
    if(N == 3){
        cout << 2 << ' ' << 3 << ' ' << 25 << endl;
        return 0;
    }
    int sum = 0;
    rep(i, 5000){
        if(sum >= N-3) break;
        cout << 6*i+2 << ' ' << 6*i+4 << ' ';
        sum += 2;
    }
    rep(i, 2500){
        if(sum >= N-1) break;
        cout << 12*i+3 << ' ' << 12*i+9 << ' ';
        sum += 2;
    }
    rep(i, 5000){
        if(sum >= N) break;
        cout << 6*(i+1) << ' ';
        sum++;
    }
    cout << endl;
}