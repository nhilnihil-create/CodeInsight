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
    string sr = s;
    reverse(sr.begin(), sr.end());
    if(s == sr){
        cout << 0 << endl;
        return 0;
    }

    string swox, swoxr;
    rep(i, s.length()){
        if(s[i] != 'x') swox += s[i];
        if(sr[i] != 'x') swoxr += sr[i];
    }
    if(swox != swoxr){
        cout << -1 << endl;
        return 0;
    }
    ll cnt = 0;
    rep(i,s.length()){
        if(s[i] == 'x' && sr[i] != 'x'){
            s.insert(s.end()-i, 'x');
            sr.insert(sr.begin()+i, 'x');
            cnt ++;
        }else if(sr[i] == 'x' && s[i] != 'x'){
            s.insert(s.begin()+i, 'x');
            sr.insert(sr.end()-i, 'x');
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}