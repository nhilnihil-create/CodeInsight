#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    vector<ll> candle1(X);
    vector<ll> candle2(Y);
    vector<ll> candle3(Z);
    rep(i,X){
        cin >> candle1[i];
    }
    rep(i,Y){
        cin >> candle2[i];
    }
    rep(i,Z){
        cin >> candle3[i];
    }
    sort(all(candle1));
    sort(all(candle2));
    sort(all(candle3));
    vector<ll> vec_first(0);
    vector<ll> vec_second(0);
    rep(i,X){
        rep(j,Y){
            vec_first.push_back(candle1[i] + candle2[j]);
        }
    }
    sort(all(vec_first));
    ll k = 3000;
    ll len = vec_first.size();
    for (ll i = 1; i <= min(k,len); i++){
        rep(j,Z){
            vec_second.push_back(vec_first[vec_first.size() - i] + candle3[j]);
        }
    }
    sort(all(vec_second));
    rep(i,K){
        cout << vec_second[vec_second.size() - i - 1] << endl;
    }
}

