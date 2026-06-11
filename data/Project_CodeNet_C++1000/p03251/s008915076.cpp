#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) REP(i, 0, n)
#define REP(i, x, n) for (int i = x; i < n; i++)
#define REPE(i, x, n) for (int i = x; i <= n; i++)
#define OP(x) cout << x << endl;
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> void chmax(T& a, T b) { if(a > b) a = b; }
template<class T> void chmin(T& a, T b) { if(a < b) b = a; }
typedef long long ll;

int main() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> vx(n);
    vector<int> vy(m);
    rep(i, n) cin >> vx[i];
    rep(i, m) cin >> vy[i];
    sort(all(vx));
    sort(all(vy));

    bool flag = false;
    for(int i = vx[n - 1] + 1; i <= vy[0]; i++){
        if(x < i && i <= y){
            flag = true;
            break;
        }else{
            continue;
        }
    }
    if(flag){
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }
}
