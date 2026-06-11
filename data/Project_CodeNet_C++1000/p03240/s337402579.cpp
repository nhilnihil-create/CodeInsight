//url:
//problem name: 

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N; cin >> N;
    veci x(N),y(N);
    veci h(N);
    int H_up;
    REP(i,N) cin >> x[i] >> y[i] >> h[i];
    for(int cy = 0; cy <= 100; cy++) {
        for(int cx = 0; cx <= 100; cx++) {
            H_up = 1e9 + 1000;
            bool ok = true;
            int H;
            bool appear = false;
            for(int i = 0; i < N; i++) {
                if(h[i] == 0) chmin(H_up,h[i]+abs(cx-x[i])+abs(cy-y[i]));
                else if(!appear) {
                    H = h[i]+abs(cx-x[i])+abs(cy-y[i]);
                    if(H > H_up) ok = false;
                    appear = true;
                } else {
                    if(H != h[i]+abs(cx-x[i])+abs(cy-y[i]) || h[i]+abs(cx-x[i])+abs(cy-y[i]) > H_up) ok = false;
                }
            }
            bool go = true;
            REP(i,N) if(max(H-abs(cx-x[i])-abs(cy-y[i]),0) != h[i]) go = false;
            if(!go) continue;
            if(ok) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
}
