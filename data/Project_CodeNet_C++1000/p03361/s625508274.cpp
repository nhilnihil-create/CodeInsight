#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

char c[55][55];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    rep(i,h)rep(j,w) cin >> c[i+1][j+1];
    rep(i,h)rep(j,w){
        if(c[i+1][j+1] == '#'){
            if(c[i][j+1] == '#') continue;
            if(c[i+1][j] == '#') continue;
            if(c[i+1][j+2] == '#') continue;
            if(c[i+2][j+1] == '#') continue;
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
