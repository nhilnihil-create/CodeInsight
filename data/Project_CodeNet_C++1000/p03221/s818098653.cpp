#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}



int main(){
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<P> py;
    map<int, map<int, int>> mmp;
    rep(i,m){
        int p,y;cin>>p>>y;
        py.push_back({p,y});
        mmp[p][y] = -1;
    }
    for(auto a : mmp){
        int idx = 1;
        for(auto b : a.second){
            mmp[a.first][b.first] = idx;
            idx++;
        }
    }
    for(auto a : py){
        printf("%06d", a.first);
        printf("%06d", mmp[a.first][a.second]);
        printf("\n");
    }
}