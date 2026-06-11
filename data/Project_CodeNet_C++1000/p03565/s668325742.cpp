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
    string ss, t, s = ""; cin >> ss >> t;
    rep(i, ss.length()){
        if(i+t.length() > ss.length()) break;
        string tmp = ss.substr(i, t.length());
        bool ok = true;
        rep(j, t.length()){
            if(tmp[j] == '?') continue;
            if(tmp[j] != t[j]){
                ok = false;
                break;
            }
        }
        if(ok){
            s = ss.substr(0, i);
            s += t;
            s += ss.substr(i+t.length());
        }
    }
    if(s == ""){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    rep(i, s.length()){
        if(s[i] == '?') s[i] = 'a';
    }
    cout << s << endl;
    return 0;
}