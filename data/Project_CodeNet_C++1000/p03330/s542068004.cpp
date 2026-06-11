#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

int main()
{
    ll i,j;
    ll n, c;
    cin >> n >> c;
    vector<vector<ll>> d(c,vector<ll>(c));
    vector<vector<ll>> color(n,vector<ll>(n));
    for(i = 0;i < c;++i){
        rep(j,c){
            cin >> d.at(i).at(j);
        }
    }
    for(i = 0;i < n;++i){
        rep(j,n){
            ll e;
            cin >> e;
            --e;
            color.at(i).at(j) = e;
        }
    }
    vector<pair<ll,ll>> tmp1(c);
    ll k;
    for(k = 0;k < c;++k){
        ll tmp = 0;
        for(i = 0;i < n;++i){
            for(j = (3*n + 3-i)%3;j < n;j += 3){
                tmp += d.at(color.at(i).at(j)).at(k);
            }
        }
        tmp1.at(k) = make_pair(tmp, k);
    }
    vector<pair<ll,ll>> tmp2(c);
    for(k = 0;k < c;++k){
        ll tmp = 0;
        for(i = 0;i < n;++i){
            for(j = (3*n + 3-i+1)%3;j < n;j += 3){
                tmp += d.at(color.at(i).at(j)).at(k);
            }
        }
        tmp2.at(k) = make_pair(tmp, k);
    }
    vector<pair<ll,ll>> tmp3(c);
    for(k = 0;k < c;++k){
        ll tmp = 0;
        for(i = 0;i < n;++i){
            for(j = (3*n + 3-i+2)%3;j < n;j += 3){
                tmp += d.at(color.at(i).at(j)).at(k);
            }
        }
        tmp3.at(k) = make_pair(tmp, k);
    }
    sort(all(tmp1));
    sort(all(tmp2));
    sort(all(tmp3));
    vector<ll> ans;
    for(i = 0;i < 3;++i){
        rep(j,3){
            rep(k,3){
                if(tmp1.at(i).second == tmp2.at(j).second || tmp2.at(j).second == tmp3.at(k).second || tmp3.at(k).second == tmp1.at(i).second){
                    continue;
                }else{
                    ans.push_back(tmp1.at(i).first + tmp2.at(j).first + tmp3.at(k).first);
                }
            }
        }
    }
    sort(all(ans));
    cout << ans.front() << endl;
    return 0;
}