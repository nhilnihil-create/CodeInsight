#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;
const ll INF = ll(1e18)+5;
ll H,W;


int main() {
    cin >> H >> W;
    ll c[10][10];
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
        cin >> c[i][j];
    } 
    vector<ll> d(10,INF);
    d[1] = 0;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push(P(0,1));
    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        if(p.first > d[p.second]){
            continue;
        }
        // cerr <<"pos="<< p.second <<"val="<< p.first << endl;
        for(int i=0;i<10;i++){
            if(i == p.second){
                continue;
            }
            if(d[i]>p.first + c[i][p.second]){
                // cerr <<"i="<<i<<"d[i]=" << d[i] << endl;
                d[i] = p.first + c[i][p.second];
                pq.push(P(d[i],i));
            }
        }
    }

    ll ans =0;
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){
        ll a;
        cin >> a;
        if(a==-1){
            continue;
        }
        ans += d[a];
    }
    cout << ans << endl;
    return 0;
}