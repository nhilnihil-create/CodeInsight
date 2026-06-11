#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N; cin >> N;
    vector<int> d(N);
    rep(i, N) cin >> d[i];

    map<int,int> mp;
    rep(i, N){
        mp[d[i]]++;
        if(mp[d[i]] > 2 || d[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    if(mp[12] > 1 || N > 24){cout << 0 << endl; return 0;}
    int ans = 0;
    vector<int> dist, u;
    for(auto e: mp){
        if(e.second == 2){
            dist.push_back(e.first);
            dist.push_back(24 - e.first);
        }else if(e.second == 1){
            //cout << e.first << e.second << endl;
            u.push_back(e.first);
        }
    }
    sort(dist.begin(), dist.end());
    //for(auto e: u) cout << e << endl;

    int k = u.size();

    for(int i = 0; i < 1 << k; i++){
        vector<int> tmp = dist;
        int tans = 12;
        tmp.push_back(0);
        for(int j = 0; j < k; j++){
            if(i & j) tmp.push_back(u[j]);
            else tmp.push_back(24-u[j]);
        }
        sort(tmp.begin(), tmp.end());
        tmp.push_back(24);
        for(int j = 1; j < tmp.size(); j++){
            //cout << tmp[j] << tmp[j-1] << endl;
            tans = min(tans, tmp[j] - tmp[j-1]);
        }
        ans = max(ans, tans);
    }

    cout << ans << endl;
}