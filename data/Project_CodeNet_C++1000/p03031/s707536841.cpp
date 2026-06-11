#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(m);
    vector<int> p(m);
    rep(i,m){
        int k;
        cin >> k;
        rep(j,k){
            int s;
            cin >> s;
            s--;
            v.at(i).push_back(s);
        }
    }
    rep(i,m) cin >> p.at(i);
    int ans = 0;
    for(int bit = 0; bit < (1 << n);bit++){
        int i = 0;
        vector<int> onoff(n,0);
        bool flg = true;
        while(i < n){
            if(bit & (1 << i)) onoff.at(i) = 1;
            i++;
        }
        rep(j,m){
            int size = v.at(j).size();
            int cnt = 0;
            rep(k,size) cnt += onoff.at(v.at(j).at(k));
            if((cnt%2)!=p.at(j)){
                flg = false;
                break;
            }
        }
        if(flg) ans++;
    }
    cout << ans << endl;
}