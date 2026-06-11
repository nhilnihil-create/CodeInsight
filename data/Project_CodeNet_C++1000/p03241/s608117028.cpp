#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double pi = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> v;
    ll maxi = 0;
    for(ll i = 1; i <= sqrt(m); i++){
        if(m % i == 0){
            ll temp = 0;
            ll i2 = m / i;
            if(n * i <= m) temp = i;
            if(n * i2 <= m) temp = i2;
            maxi = max(maxi,temp); 
        } 
    }
    cout << maxi << endl;
    return 0;
}