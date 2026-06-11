#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;
    map<int, int> mp;
    vector<int> values;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        values.push_back(a);
        mp[a]++;
    }
 
    sort(values.rbegin(), values.rend());
    values.erase(std::unique(values.begin(), values.end()), values.end());
 
    int ans = 0;
    for(auto a : values){
        for(int i=30; i>=0; i--){
            if(mp[a] == 0) break;
            int b = (1<<i) - a;
            if(!mp.count(b)) continue;
            int add;
            if(a == b){
                add = mp[a]/2;
            }else{
                add = min(mp[a], mp[b]);
            }
            ans += add;
            mp[a] -= add;
            mp[b] -= add;
        }
    }
    cout << ans << endl;
    return 0;
}