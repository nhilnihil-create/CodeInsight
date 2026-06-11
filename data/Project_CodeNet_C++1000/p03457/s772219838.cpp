#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int curT = 0, curX = 0, curY = 0;
    bool ok = true;
    rep(i,n){
        int t, x, y;
        cin >> t >> x >> y;
        if(t - curT < abs(curX - x) + abs(curY - y)) ok = false;
        if(abs((t - curT) - (abs(curX - x) + abs(curY - y))) % 2 == 1) ok = false;
        curT = t;
        curX = x;
        curY = y;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
