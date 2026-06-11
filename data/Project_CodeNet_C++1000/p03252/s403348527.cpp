#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    string s, t; cin >> s >> t;
    vector<ll> sr(26, -1), tr(26, -1);
    rep(i, s.length()){
        if(sr[s[i] - 'a'] == -1) sr[s[i] - 'a'] = t[i] - 'a';
        else{
            if(sr[s[i] - 'a'] != t[i] - 'a'){
                cout << "No" << endl;
                return 0;
            }
        }
        if(tr[t[i] - 'a'] == -1) tr[t[i] - 'a'] = s[i] - 'a';
        else{
            if(tr[t[i] - 'a'] != s[i] - 'a'){
                cout << "No" << endl;
                return 0;
            }
        }
    }    
    
    cout << "Yes" << endl;
    return 0;
}