#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long,long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int H,W; cin >> H >> W;
    vecveci A(H,veci(W));
    REP(i,H) REP(j,W) cin >> A[i][j];
    vector<tuple<int,int,int,int>> ans;
    for(int i = 0; i < H; i++) {
        if(i%2 == 0) {
            for(int j = 0; j < W; j++) {
                if(A[i][j]%2 == 0) continue;
                if(j != W-1) {
                    ans.push_back(make_tuple(i,j,i,j+1));
                    A[i][j]--;
                    A[i][j+1]++;
                } else {
                    if(i+1 < H) {
                        ans.push_back(make_tuple(i,j,i+1,j));
                        A[i][j]--;
                        A[i+1][j]++;
                    }
                }
            }
        } else {
            for(int j = W-1; j >= 0; --j) {
                if(A[i][j]%2 == 0) continue;
                if(j != 0) {
                    ans.push_back(make_tuple(i,j,i,j-1));
                    A[i][j]--;
                    A[i][j-1]++;
                } else {
                    if(i+1 < H) {
                        ans.push_back(make_tuple(i,j,i+1,j));
                        A[i][j]--;
                        A[i+1][j]++;
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(auto p : ans) {
        cout << get<0>(p)+1 << " " << get<1>(p)+1 << " " << get<2>(p)+1 << " "  << get<3>(p)+1 << endl;
    }
}
