#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> time(c, vector<int>(100005, 0));
    rep(i, n){
        int s, t, C;
        cin >> s >> t >> C;
        C--;
        time[C][s]++;
        time[C][t]--;
    }

    rep(i, c){
        for(int j = 1; j < 100005; ++j){
            if(time[i][j] > 0){
                time[i][j - 1] += time[i][j];
                time[i][j] = 0;
            }
        }
    }

    rep(i, 100005){
        for(int j = 1; j < c; ++j){
            time[0][i] += time[j][i];
        }
    }

    vector<int> sum(100005, 0);
    sum[0] = time[0][0];
    int ans = sum[0];
    rep(i, 100004){
        sum[i + 1] = sum[i] + time[0][i + 1];
        ans = max(ans, sum[i + 1]);
    }
    cout << ans << endl;
}