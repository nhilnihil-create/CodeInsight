#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<int,int> mp;
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        mp[i] = cnt;
        if(s[i] == 'A' && s[i+1] == 'C') cnt++;
        
    }    
    mp[n-1] = cnt;
    vector<int> ans;
    for(int i = 0; i < q; i++){
        int l,r;
        cin >> l >> r;
        l--;r--;
        ans.push_back(mp[r]-mp[l]);
    }
    for(auto p:ans) cout << p << endl;
    return 0;
}