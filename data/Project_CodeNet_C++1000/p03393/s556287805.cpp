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
    string s; cin >> s;
    vector<ll> ss(26, 0);
    rep(i, s.length()){
        ss[s[i] - 'a']++;
    }
    string st = s;
    if(s.length() < 26){
        char v = ' ';
        rep(i, ss.size()) if(ss[i]==0){ v = i + 'a'; break;}
        cout << s << v << endl;
    }else{
        vector<ll> tmp;
        for(ll i = s.length()-1; i >= 0; --i){
            if(i == s.length()){
                tmp.push_back(s[i]);
                continue;
            }
            if(s[i] > s[i+1]){
                tmp.push_back(s[i]);
            }else{
                tmp.push_back(s[i]);
                sort(tmp.begin(), tmp.end());
                auto it = find(tmp.begin(), tmp.end(), s[i]);
                s[i] = *(++it);
                s.erase(s.begin()+i+1, s.end());
                break;
            }

        }
        if(s == st) cout << -1 << endl;
        else cout << s << endl;
    }
    return 0;
}