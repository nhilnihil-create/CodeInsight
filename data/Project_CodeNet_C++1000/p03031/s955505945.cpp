#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,ans=0;
    cin >> n >> m;
    vector<vector<int>> sw(m);
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int d;
            cin >> d;
            d--;
            sw[i].push_back(d);
        }
    }
    int p[m];
    for(int i=0;i<m;i++) cin >> p[i];
    for(int i=0;i<(1<<n);i++){//スイッチを総当たり
        bitset<10> s(i);
        bool AllLight = 1;
        for(int j=0;j<m;j++){//電球の点灯判定
            int cnt = 0;//何個スイッチオンか
            for(auto k:sw[j]){
                if(s.test(k)) cnt++;
            }
            if(cnt%2!=p[j]) AllLight=0;
        }
        if(AllLight) ans++;
    }
    cout << ans << endl;
    
}
