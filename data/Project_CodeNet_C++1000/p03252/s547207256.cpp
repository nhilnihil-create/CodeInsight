#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

string func(string s){
    int base = 0;
    int s2n[26];
    rep(i, 26)s2n[i] = -1;

    rep(i, s.size()){
        if(s2n[s[i]-'a'] < 0){
            s2n[s[i]-'a'] = base;
            s[i] = char('0' + base);
            base++;
        }
        else s[i] =  char('0' + s2n[s[i]-'a']);
    }

    return s;
}

int main(){
    string s, t;
    cin >> s >> t;

    s = func(s);
    t = func(t);

    if(s == t)cout << "Yes\n";
    else cout << "No\n";
}