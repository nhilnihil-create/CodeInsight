#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG
typedef long long ll;

int main(){
    int n, m;
    map<string, ll> mp;
    cin >> n;
    rep(i, n){
        string s;
        cin >> s;
        mp[s]++;
    }
    cin >> m;
    rep(i, m){
        string s;
        cin >> s;
        mp[s]--;
    }
    ll max = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        if(itr->second > max) max = itr->second;
    }
    cout << max << endl;
}