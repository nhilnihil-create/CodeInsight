#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N; cin >> N;
    vecveci F(N,veci(10));
    vecveci P(N,veci(11));
    REP(i,N) REP(j,10) cin >> F[i][j];
    REP(i,N) REP(j,11) cin >> P[i][j];
    int ans = 1000000000;
    ans *= -1;
    for(int bit = 0; bit < (1<<10); bit++) {
        if(bit == 0) continue;
        int total = 0;
        REP(i,N) {
            int cnt = 0;
            REP(j,10) if((bit & (1<<j)) && F[i][j]) cnt++;
            //cout << cnt << endl;
            total += P[i][cnt];
        }
        chmax(ans,total);
    }
    cout << ans << endl;
}