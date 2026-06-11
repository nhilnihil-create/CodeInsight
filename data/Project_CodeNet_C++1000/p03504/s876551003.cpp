#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    vector<ll>cnt(1001001,0);
    ll n,c;cin >>n>>c;
    vector<pair<ll,P>>ch(n);
    for (int i = 0; i < n; ++i) {
        ll s,t,c;
        cin >>s>>t>>c;
        P p={s,t};
        ch[i]={c,p};
    }
    sort(all(ch));
    for (int i = 0; i < n;i++) {
        if(ch[i].first==ch[i+1].first){
            ll s=ch[i].second.first;
            ll f;
            while (ch[i].first==ch[i+1].first&&ch[i].second.second==ch[i+1].second.first){
                i++;
            }
            f=ch[i].second.second;
            cnt[s-1]++;
            cnt[f]--;
        }
        else {
            ll s=ch[i].second.first;
            ll f=ch[i].second.second;
            cnt[s-1]++;
            cnt[f]--;
        }
    }
//    for (int i = 0; i < 13; ++i) {
//        cout <<i<<" "<<cnt[i]<<endl;
//    }
    ll ans=0;ll now=0;
    for (int i = 0; i < 1001001; ++i) {
        now+=cnt[i];
        ans=max(ans,now);
    }
    cout <<ans <<endl;
    return 0;
}