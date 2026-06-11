#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int d,g;
    cin >> d >> g;
    vector<pair<int,int>> pro(d);
    for(int i = 0; i < d; i++){
        int a,b;
        cin >> a >> b;
        pro[i] = {a,b};
    }    
    map<int,bool> memo;
    int ans = mod;
    for(int bit = 0; bit < (1<<d); bit++){
        memo.clear();
        int can = 0;
        int cnt = 0;
        for(int i = 0; i < d; i++){
            if(bit & (1<<i)) memo[i] = true;
        }
        for(int i = 0; i < d; i++){
            if(memo[i]){
                can += pro[i].second;
                can += (i+1)*100*pro[i].first;
                cnt += pro[i].first;
            }
        }
        if(can >= g){
            ans = min(ans,cnt);
            continue;
        }
        for(int i = d-1; i >= 0; i--){
            if(!memo[i]){
                for(int j = 0; j < pro[i].first; j++){
                    can += (i+1)*100;
                    cnt++;
                    if(can >= g){
                        ans = min(ans,cnt);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}