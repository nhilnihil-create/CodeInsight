#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;
/* -- template -- */

const int T_MAX = 1e5 + 1;
int rec[30][T_MAX];
int sum[T_MAX];
int main(){
    int N, C; cin >> N >> C;
    rep(i, N){
        int s, t, c; cin >> s >> t >> c;
        --c;
        rec[c][s] += 1;
        rec[c][t] -= 1;
    }
    rep(i, C){
        rep(j, T_MAX - 1){
            rec[i][j + 1] += rec[i][j];
            if(rec[i][j] == 0 && rec[i][j + 1] == 1)rec[i][j] = 1;
        }
    }
    int maxv = 0;
    rep(i, T_MAX){
        rep(j, C){
            sum[i] += rec[j][i];
        }
        maxv = max(maxv, sum[i]);
    }
    cout << maxv << endl;
}
