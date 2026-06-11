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
    vector<vector<int>> d(c, vector<int>(c)), col(n, vector<int>(n));
    rep(i, c)rep(j, c)cin >> d[i][j];
    rep(i, n)rep(j, n)cin >> col[i][j];
    vector<map<int, int>> mp(3);
    rep(i, n)rep(j, n){
        mp[(i+j)%3][col[i][j]-1]++;
    }

    int ans = 1001001001;
    rep(i, c)rep(j, c)rep(k, c){
        if(i==j || j==k || k==i)continue;
        int sum = 0;
        rep(l, 3){
            for(auto it = mp[l].begin(); it != mp[l].end(); it++){
                int color = it->first;
                int num = it->second;
                if(l == 0)sum += d[color][i] * num;
                else if(l == 1)sum += d[color][j] * num;
                else sum += d[color][k] * num;
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}