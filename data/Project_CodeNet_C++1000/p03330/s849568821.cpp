#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main(){

    int N, C;
    cin >> N >> C;
    int D[C+1][C+1];
    int color[N+1][N+1];
    rep(i, C) {
        rep(j, C) {
            cin >> D[i][j];
        }
    }

    rep(i, N){
        rep(j, N){
            cin >> color[i][j];
            color[i][j]--;
        }
    }

    ll ans = 1000000000000000;

    ll cost[3][C];

    rep(i, 3) {
        rep(j, C) {
            cost[i][j] = 0;
        }
    }

    rep(i, C) {
        rep(a, N) {
            rep(b, N) {
                if (color[a][b] != i ) {
                    cost[(a+b)%3][i] += D[color[a][b]][i];
                }
            }
        }
    }
    rep(i, C) {
        rep(j, C) {
            rep(k, C) {
                if (i == j || j == k || k == i) {
                    continue;
                }


                chmin(ans, cost[0][i] + cost[1][j] + cost[2][k]);
            }
        }
    }



    cout << ans << endl;

}