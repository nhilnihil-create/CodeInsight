#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

int main(){
    string s; cin >> s;
    map<char, int> mp;
    for(int i=0; i<s.size(); i++) mp[s[i]]++;

    pair<char, int> pa = {'a', 0}; 
    for(auto itr=mp.begin(); itr!=mp.end(); itr++){
        if(itr->second > pa.second){
            pa.second = itr->second;
            pa.first = itr->first;
        }
    }

    int must = 2*(pa.second-1);
    int ans = 0;

    for(auto itr=mp.begin(); itr!=mp.end(); itr++){
        if(itr->first == pa.first) continue;
        ans += min(pa.second-1, itr->second);
    }

    if(ans >= must) cout << "YES" << endl;
    else cout << "NO" << endl;
}