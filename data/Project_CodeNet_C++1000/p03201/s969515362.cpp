#include<bits/stdc++.h>
using namespace std;
using Int = long long;
auto find_pair(Int a){
    for(Int i = 1; i < 32; ++i){
        Int bit = (1LL << i);
        if( bit > a) return bit - a;
    }
    return 0LL;
}
signed main(){
    Int N; cin >> N;
    vector<Int>A(N);
    for(auto& e : A) cin >> e;
    map<Int,Int,greater<>>cnt;
    for(auto e : A) cnt[e]++;
    Int ans = 0;
    for(auto itr : cnt){
        Int key = itr.first;
        Int value = itr.second;
        if(value == 0) continue;
        Int pir = find_pair(key);
        if(pir == key){
            ans  += value /2;
        } else {
            if(cnt.find(pir) == cnt.end()) continue;
            ans += min(value, cnt[pir]);
            cnt[pir] -= min(value, cnt[pir]);
            
        }
        cnt[key] = 0;
    }
    cout << ans << endl;
}



