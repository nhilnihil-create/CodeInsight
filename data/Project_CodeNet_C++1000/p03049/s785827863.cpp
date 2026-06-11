#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<string> s(n);
    ll ans = 0;
    ll a = 0;
    ll b = 0;
    ll ab = 0;
    for(i = 0;i < n;++i){
        cin >> s.at(i);
        if(s.at(i).at(0) == 'B' && s.at(i).back() == 'A') ++ab;
        else if(s.at(i).at(0) == 'B') ++b;
        else if(s.at(i).back() == 'A') ++a;
        rep(j, s.at(i).size()-1){
            if(s.at(i).substr(j,2) == "AB") ++ans;
        }
    }
    ll tmp = 0;
    if(b >= a + ab){
        tmp = a + ab;
    }else if(a >= b + ab){
        tmp = b + ab;
    }else if(a + b != 0){
        tmp = ab + min(a,b);
    }else{
        tmp = ab-1;
    }
    cout << ans + tmp << endl;
    return 0;
}