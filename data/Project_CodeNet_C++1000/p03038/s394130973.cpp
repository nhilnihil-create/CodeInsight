#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n,m;
    int now=0;

    cin >> n >> m;
    vector<ll> card(n);
    vector<pair<ll,ll>> action;
    rep(i,n) cin >> card[i];
    sort(card.begin(),card.end());
    rep(i,m){
        ll b,c;
        cin >> b >> c;
        action.push_back(make_pair(c,b));
    }
    sort(action.rbegin(),action.rend());
    rep(i,m){
        int b = action[i].second;
        int c = action[i].first;
        rep(j,b){
            if(now>n) break;
            if(card[now]<c) card[now] = c;
            now++;
            //cout << 1 ;
        }
        if(now>n) break;
    }
    ll ans=0;
    rep(i,n) ans += card[i];
    cout << ans << endl;

}