#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e9;
  
int main() {
    int n,c; cin >> n >> c;
    vector<vector<int>> time(1e5 + 1,vector<int>(c,0));

    for (int i = 0; i < n; i ++) {
        int s,t,c1; cin >> s >> t >> c1;
        c1 --;
        time[s][c1] ++;
        time[t][c1] --;
    }

    for (int i = 0; i < 1e5 ; i ++) {
        for (int j = 0; j < c; j ++) {
            if (time[i][j] == 0 && time[i + 1][j] == 1) {
                time[i][j] = 1;
                time[i + 1][j] = 0;
            }
        }
    }

    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < 1e5 + 1; i ++ ) {
        for (int j = 0; j < c ; j ++) {
            tmp += time[i][j];
        }
        ans = max(ans,tmp);
    }

    cout << ans << endl;
}