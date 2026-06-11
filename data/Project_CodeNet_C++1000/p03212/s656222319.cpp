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

ll Str2Long(string s){
    reverse(ALL(s));
    ll n = 0;
    rep(i, s.size()){
        n += (s[i]-'0')*pow(10, i);
    }
    return n;
}

ll func(string s, ll n){
    if(Str2Long(s) > n)return 0;
    ll res = 0;

    bool has3, has5, has7;
    has3 = has5 = has7 = false;

    rep(i, s.size()){
        if(s[i] == '3')has3 = true;
        else if(s[i] == '5')has5 = true;
        else has7 = true;
    }
    if(has3 && has5 && has7 && Str2Long(s) <= n)res++;
    
    res += func(s+'3', n) + func(s+'5', n) + func(s+'7', n);

    return res;
}

int main(){
    ll n;
    cin >> n;

    cout << func("", n) << endl;
}