#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
ll INF = (1LL << 60) - 1;
int MOD = 1e9+7;
int calc(ll x){
    int res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}
string to_str(ll A){
    stringstream ss;
    ss << A;
    return ss.str();
}
ll next(ll x){
    vector<ll> cand;
    cand.push_back(x);
    ll d = 10;
    rep(i,0,15){
        cand.push_back(d * (x / d + 1) - 1);
        //if(d > x * 10)break;
        d *= 10;
    }
    double mini = 1e16;
    ll ans;
    for(auto i:cand){
        //cout << i << " ";
        if(mini > 1. * i / calc(i)){
            mini = 1. * i / calc(i);
            ans = i; 
        }
    }
    //cout << endl;
    return ans;
}
main(){
    int K;
    cin >> K;   
    ll x = 1;
    rep(i,0,K){
        cout << x << endl;
        x = next(x+1);
    }
}