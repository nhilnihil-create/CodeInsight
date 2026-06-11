#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(int i = k; i < (n); i++)

int main(){
    int n;
    cin >> n;
    vector<int> station(n, 0);
    vector<vector<int>> time;
    int c, s, f;
    rep(i, 0, n-1){
        cin >> c >> s >> f;
        vector<int> si = {c, s, f};
        time.push_back(si);
    }
    rep(i, 0, n-1){
        int t = time[i][0] + time[i][1];
        rep(j, i+1, n-1){
            if (t < time[j][1]) t = time[j][1];
            else if (t % time[j][2] != 0) t += time[j][2] - t % time[j][2];
            t += time[j][0];
        }
        station[i] = t;
    }
    for (auto s:station) cout << s << endl;
    return 0;
}