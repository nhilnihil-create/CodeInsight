#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main(){
    ll x, y;
    cin >> x >> y;
    int cnt = 1;
    ll now = x;
    while (now * 2 <= y) {
        now *= 2;
        cnt++;
    }
    cout << cnt << endl;
}