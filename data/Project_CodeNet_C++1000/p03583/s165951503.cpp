#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    ll N; cin >> N;
    int L = 3500;
    rng(h, 1, L+1) {
        rng(n, h, L+1) {
            ll ls = 4*h*n - N*h - N*n;
            ll rs = N*n*h;
            if (ls > 0 && rs%ls == 0) {
                cout << h << " " << n << " " << rs/ls << endl;
                return 0;
            }
        }
    }
    return 0;
}