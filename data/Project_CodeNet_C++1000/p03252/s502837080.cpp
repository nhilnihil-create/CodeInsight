#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s,t;
    cin >> s >> t;
    char c = s[0];
    map<char,int> smemo;
    map<char,int> tmemo;
    rep(i,s.length()){
        smemo[s[i]]++;
        tmemo[t[i]]++;
    }
    bool ok = true;
    rep(i,s.length()){
        if(smemo[s[i]] != tmemo[t[i]]){
            ok = false;
        }
    }
    if(ok){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    cout << endl;
    return 0;
}
