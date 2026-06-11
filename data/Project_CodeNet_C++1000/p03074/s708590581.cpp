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
    svpl.emplace_back(tmp,num);
    ll m = svpl.size();
    ll ans = 0;
    /**
    if(svpl.front().first == 0){
        for(i = 0;i < min(m, 2*k);++i){
            tmpans += svpl.at(i).second;
        }
    }else{
        for(i = 0;i < min(m, 2*k+1);++i){
            tmpans += svpl.at(i).second;
        }
    }
    **/
    for(i = 0;i < max(1ll, m-2*k+1);++i){
        ll tmpans = 0;
        if(svpl.at(i).first == 0){
            for(j = i;j < min(m, i + 2*k);++j){
                tmpans += svpl.at(j).second;
            }
        }else{
            for(j = i;j < min(m, i + 2*k+1);++j){
                tmpans += svpl.at(j).second;
            }
        }
        ans = max(ans, tmpans);
    }
    cout << ans << endl;
    return 0;
}