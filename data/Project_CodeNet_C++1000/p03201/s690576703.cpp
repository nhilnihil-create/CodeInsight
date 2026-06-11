#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    map<int, int> mp;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        v.push_back(a);
        mp[a]++;
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(auto e: v){
        if(mp[e] == 0)continue;
        int num = 1;
        while(num <= e)num <<= 1;
        //cerr << num << endl;
        if(num-e != e && mp[num-e] > 0 || num-e == e && mp[e] > 1){
            ans++;
            mp[num-e]--;
        }
        mp[e]--;
    }

    cout << ans << endl;

    return 0;
}