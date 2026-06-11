#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
//const int MOD = 1e9+7;

int main(){
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<int> ans;
    for(auto x:mp)
        if(x.second)
            ans.push_back(x.second);
        
    sort(ans.begin(), ans.end());
    if((int)ans.size() <= k){
        cout << 0;
        return 0;
    }

    int z=0, sz=ans.size();
    for(int i=0; sz>0 && i<(int)ans.size(); ++i){
        z += ans[i];
        --sz;
        if(sz <= k)
            break;
    }
    cout << z;
}
