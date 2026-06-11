#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
    ll n; cin >> n;
    vector<pair<ll,ll>> ab(n);
    rep(i,n) cin >> ab.at(i).first;
    rep(i,n) cin >> ab.at(i).second;

    std::sort(ab.begin(), ab.end(), [](const pair<ll,ll> x, const pair<ll,ll> y) {
        return x.first - x.second > y.first - y.second;
    });

    ll dif = 0;
    ll ans = 0;

    for(int i=n-1;i>=0;i--){
        if(ab.at(i).first >= ab.at(i).second) break;
        dif += (ab.at(i).second - ab.at(i).first);
        ans++;                
    }

    ll x = 0;

    while(dif>0){
        if(ab.at(x).first <= ab.at(x).second) break;
        dif -= ab.at(x).first - ab.at(x).second;
        ans++, x++;
        if(dif<=0) break;
    }

    if(dif>0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    //rep(i,n) cout << ab.at(i).first << " " << ab.at(i).second << endl;   
}