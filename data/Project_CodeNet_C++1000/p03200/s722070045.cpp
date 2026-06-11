#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){
    string s;
    cin >> s;
    vector<int> x;
    rep(i,s.size()){
        if(s[i] == 'W'){
            x.push_back(i+1);
        }
    }

    int count=1;
    ll ans = 0;
    for(auto v : x){
        ans += (v-count);
        count++;
    }
    
    cout << ans << endl;
}