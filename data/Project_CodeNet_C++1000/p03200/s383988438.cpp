#include "bits/stdc++.h"
using namespace std;
#define int long long 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int cnt=0,ans=0;

    vector<int>pos;
    for(int i=0;i<s.length();i++){
        if(s[i]=='W')pos.push_back(i);
    }

    for(int i=0;i<pos.size();i++){
        ans+=pos[i]-i;
    }

    cout<<ans<<endl;
}

