#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()
 
int main(){
    ll n;
    cin >> n;
    vector<ll> d;
    int cnt[24]={};
    bool flag = false;
    rep(i, n){
        int in;
        cin >> in;
        if(cnt[in]<2)d.push_back(in);
        cnt[in]++;
        if(cnt[in]>2)flag = true;
    }
    if(flag||cnt[0]+cnt[12]>2||d.size()>=24){
        cout << 0;
        return  0;
    }
    if(d.size()>18){
        cout << 1;
        return 0;
    }

    ll ans = 0;
    sort(ALL(d));
    ll mn = min(d.front(), 24-d.back());
    ll time = 0;
    rep(i, (1<<d.size())){
        ll s  = mn;
        rep(j, d.size()){
            ll city1;
            if(i&(1<<j))city1 = d[j];
            else city1 = 24-d[j];
            for(ll k=j+1; k<d.size(); ++k){
                ll city2;
                if(i&(1<<k))city2 = d[k];
                else city2 = 24-d[k];
                ll dif = abs(city1-city2);
                s = min(s, min(dif, 24-dif));
            }
        }
        ans = max(s, ans);
    }
    cout << ans << endl;
}