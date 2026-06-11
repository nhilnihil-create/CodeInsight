#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;
    ll ans = 0;

    if(n > m) swap(n,m);
    if(n == 1 && m == 1){
        put(1);
    }else if(n == 1){
        put(m - 2);
    }else if(n == 2){
        put(0);
    }else{
        put((n-2)*(m-2));
    }
}