/*
      author  : nishi5451
      created : 14.08.2020 17:35:05
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    map<string,int> mp;
    int n,m;
    cin >> n;
    rep(i,n){
        string s;
        cin >> s;
        mp[s]++;
    }
    cin >> m;
    rep(i,m){
        string s;
        cin >> s;
        mp[s]--;
    }
    int ans = 0;
    string key;
    for(auto a : mp){
        if(a.second > ans){
            key = a.first;
            ans = a.second;
        }
    }
    if(ans == 0){
        cout << 0 << endl;
    }
    else cout << ans << endl;
   
    return 0;
}