#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    vector<ll> x(n), y(n); rep(i,n) cin >> x[i];

    y = x;

    sort(x.begin(),x.end());

    for(long long i = 0; i < n; i++){
        if(y[i] < x[n/2]){
            put(x[n/2]);
        }else{
            put(x[n/2-1]);
        }
    }
}