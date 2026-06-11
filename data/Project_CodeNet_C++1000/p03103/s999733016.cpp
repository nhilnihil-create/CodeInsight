#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    int N,M;
    cin >> N >> M;
    
    vector<pair<ll,ll>> shop;
    
    //店を取得して安い順
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        shop.push_back(make_pair(a,b));
    }
    sort(shop.begin(), shop.end());
    
    
    int i=0;
    ll now_M = M;
    ll totalcost=0;
    while(now_M>0){
        if(shop[i].second <= now_M){
            now_M -= shop[i].second;
            totalcost += shop[i].first * shop[i].second;
        }else if(shop[i].second > now_M){
            totalcost += shop[i].first * now_M;
            now_M = 0;
        }
        
        i++;
    }
    
    cout << totalcost << endl;
    
    /*
    for(pair<ll,ll> t:shop){
        ll x,y;
        x = t.first;
        y = t.second;
        cout << x << " " << y <<endl;
    }
    */
}
