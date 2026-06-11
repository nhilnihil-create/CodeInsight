#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<ll,ll>> svpl;
    char tmp = s.at(0);
    ll num = 1;
    for(i = 1;i < n;++i){
        if(s.at(i) == tmp) ++num;
        else{
            svpl.emplace_back(tmp-'0',num);
            tmp = s.at(i);
            num = 1;
        }
    }
    svpl.emplace_back(tmp-'0',num);
    ll m = svpl.size();
    ll ans = 0;
    if(svpl.front().first == 0){
        for(i = 0;i < min(m, 2*k);++i){
            ans += svpl.at(i).second;
        }
    }else{
        for(i = 0;i < min(m, 2*k+1);++i){
            ans += svpl.at(i).second;
        }
    }
    ll tmpval = ans;
    ll last;
    if(svpl.back().first == 0){
        last = m-2*k+1;
    }else{
        last = m-2*k-1;
    }
    
    for(i = 1;i <= last;++i){
        if(svpl.at(i).first == 0){
            tmpval -= svpl.at(i-1).second;
        }else{
            tmpval -= svpl.at(i-1).second;
            if(i+2*k-1 <= m-1) tmpval += svpl.at(i+2*k-1).second;
            if(i+2*k <= m-1) tmpval += svpl.at(i+2*k).second;
        }
        ans = max(ans, tmpval);
    }
    
    cout << ans << endl;
    return 0;
}