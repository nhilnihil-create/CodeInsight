#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    map<int,int> mp;
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        mp[a]++;
    }
    if(mp.size() <= k){
        cout << 0 << endl;
        return 0;
    }
    vector<int> vec;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        vec.push_back(it->second);
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for(int i = 0; i < mp.size()-k; ++i){
        ans += vec[i];
    }
    cout << ans << endl;
    return 0;
}