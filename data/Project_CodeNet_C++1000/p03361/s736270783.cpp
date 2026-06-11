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

veci dx = {-1,0,1,0};
veci dy = {0,-1,0,1};

int main() {
    int H,W; cin >> H >> W;
    vector<string> S(H);
    REP(i,H) cin >> S[i];
    REP(i,H) REP(j,W) {
        bool ok = false;
        if(S[i][j] == '#') {
            REP(dir,4) {
                int ni = i + dy[dir];
                int nj = j + dx[dir];
                if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if(S[ni][nj] == '.') continue;
                else ok = true;
            }
            if(ok == false) {
                cout <<  "No" << endl;
                return 0;
            } 
        }
    }
    cout << "Yes" << endl;
}