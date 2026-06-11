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
    int a,b,c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    int ans=a+b+c;
    int m = max(max(a,b),c);
    // cout << m << ans;
    ans-=m;
    rep(i,k){
        m*=2;
    }
    ans+=m;
    cout << ans;

    return 0;
}