#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    string s;
    cin >> s;

    if(s[0] != '1' || s.back() != '0'){
        cout << -1 << endl;
        return 0;
    }

    int n = s.size();
    for(int i=0;i<(int)s.size()/2;++i){
        if(s[i] != s[n-i-2]){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<pair<int, int>> ans;
    int par = n;
    for(int i=n-2;i>=0;--i){
        ans.emplace_back(i+1, par);
        if(s[i] == '1')par = i+1;
    }

    for(auto e: ans){
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}