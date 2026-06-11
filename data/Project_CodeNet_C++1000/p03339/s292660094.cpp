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
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll e=0,w=0;
    rep(i,n){
        if(s[i]=='E') e++;
        else w++;
    }

    ll ans = 1000000;

    ll en=0,wn=0;

    rep(i,n){
        ll tmp;
        if(s[i]=='E'){
            en++;
            tmp = wn + e - en;
        }else{
            tmp = wn + e - en;
            wn++;
        }
        ans = min(ans,tmp);
    }

    cout << ans << endl;

    return 0;
}