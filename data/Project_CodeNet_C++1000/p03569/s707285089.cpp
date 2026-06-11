#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s;
    cin >> s;
    string t;
    for(i = 0;i < s.size();++i){
        if(s.at(i) != 'x') t.push_back(s.at(i));
    }
    for(i = 0;i < t.size();++i){
        if(t.at(i) != t.at(t.size()-i-1)){
            cout << -1 << endl;
            return 0;
        }
    }
    ll n = t.size();
    vector<ll> ind(n);
    ll now = 0;
    for(i = 0;i < s.size();++i){
        if(s.at(i) != 'x'){
            ind.at(now) = i;
            ++now;
        }
    }
    ll ans = 0;
    if(n%2){
        for(i = 0;i <= (n-1)/2;++i){
            if(i == 0){
                ll tmp1 = ind.at(i) - 0;
                ll tmp2 = s.size() - 1 - ind.at(n-1-i);
                ans += abs(tmp1 - tmp2);
            }else{
                ll tmp1 = ind.at(i) - ind.at(i-1);
                ll tmp2 = ind.at(n-i) - ind.at(n-1-i);
                ans += abs(tmp1 - tmp2);
            }
        }
    }else{
        for(i = 0;i < n/2;++i){
            if(i == 0){
                ll tmp1 = ind.at(i) - 0;
                ll tmp2 = s.size() - 1 - ind.at(n-1-i);
                ans += abs(tmp1 - tmp2);
            }else{
                ll tmp1 = ind.at(i) - ind.at(i-1);
                ll tmp2 = ind.at(n-i) - ind.at(n-1-i);
                ans += abs(tmp1 - tmp2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}