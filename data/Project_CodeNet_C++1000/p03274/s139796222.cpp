#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    ll psize=0,msize=0;
    ll p[100001],m[100001];
    rep(i,n){
        ll tmp;
        cin >> tmp;
        if(tmp<0){
            m[msize] = -tmp;
            msize++;
        }else{
            p[psize] = tmp;
            psize++;
        }
    }
    sort(m,m+msize);
    ll ans = 1000000000;
    
    rep(i,k){
        if(i<psize&&k-i-2<msize&&k-i-2>=0){
            ans = min({ans,2*m[k-i-2]+p[i],m[k-i-2]+2*p[i]});
        }
    }
    if(k<=psize) ans = min(ans,p[k-1]);
    if(k<=msize) ans = min(ans,m[k-1]);


    cout << ans << endl;

    return 0;
}