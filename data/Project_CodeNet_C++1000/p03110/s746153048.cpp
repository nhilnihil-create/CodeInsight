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
    long double ans=0.0;
    rep(i,n){
        long double m;
        string s;
        cin >> m >> s;
        if(s == "JPY"){
            ans += m;
        }
        else{
            ans += m*380000.0;
        }
    }
    cout << ans;

    return 0;
}