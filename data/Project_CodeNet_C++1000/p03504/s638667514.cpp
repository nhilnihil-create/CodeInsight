#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int main() {
    int N, C; cin >> N >> C;
    vector<vector<int>> sum(200010, vector<int>(35));

    rep(i,N) {
        int s, t, c; cin >> s >> t >> c;
        c--;
        sum[s*2-1][c]++;
        sum[t*2+1][c]--;
    }

    // rep(i,C) {
    //     rep(j,30) cout << sum[j][i] << " ";
    //     cout << endl;
    // }

    int ans = 0, tmp;
    vector<int> state(C);
    rep(i,200000+1) {
        rep(j,C) {
            state[j] += sum[i][j];
        }
        tmp = 0;
        rep(j,C) {
            if (state[j]) tmp++;
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}