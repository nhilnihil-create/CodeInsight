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
    ll n; cin >> n;
    vector<string> s(n);
    ll ab = 0, a = 0, b = 0;
    vector<pair<char, char>> sp;
    rep(i, n){
        cin >> s[i];
        char f = s[i][0], e = s[i][s[i].size()-1];
        if(s[i][0] == 'B' || s[i][s[i].size() - 1] == 'A'){
            sp.emplace_back(f, e);
            if(f == 'B') b++;
            if(e == 'A') a++;
        }
        
        ll in = 0;
        while(in != string::npos){
            in = s[i].find("AB", in);
            if(in != string::npos){
                ab++;
                in++;
            }
        }
    }
    ll cat = min(a, b);
    if(a > 0 && a == b && sp.size() == a) cat--;
    //printf("%lld %lld %lld %lld %d\n", ab, a, b, cat, (int)sp.size());
    cout << ab + cat << endl;
    return 0;
}