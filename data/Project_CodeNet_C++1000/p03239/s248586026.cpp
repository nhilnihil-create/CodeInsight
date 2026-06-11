#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n, T; cin >> n >> T;
    int ct[n][2];
    int d=1010;
    rep(i, n){
            int c, t;
            cin >> c >>t;

            if(t<=T){
                d = min(d, c);
                }
    }
    if(d==1010) out("TLE")
    else out(d);
}