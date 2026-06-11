#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
const int INF = 1001001001;

int main(){
    
    int n; cin>>n;
    map<string,int> mp;
    string s,t;
    
    bool ok = true;
    for(int i=0; i<n; i++){
        cin>>s;
        if(mp.count(s))         ok = false;
        if(i && s[0]!=t.back()) ok = false;
        
        mp[s]++;
        t = s;
    }
    
    if(ok)cout << "Yes" << endl;
    else  cout << "No" << endl;
    
    return 0;
}