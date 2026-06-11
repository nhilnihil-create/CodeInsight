#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    ll n;cin >> n;
    ll ans = 0;
    set<ll> div;
    for(int i = 1;i<=sqrt(n);i++){
        if(n%i==0) {
            div.insert(i);
            div.insert(n/i);
        }
    }
    div.insert(n);

    for(auto it=(--div.end());it!=div.begin();it--){
        if((*it)-1>sqrt(n)){
            ans += *it;
            ans -= 1;
        }else break;
    }

    cout << ans << endl;


 }