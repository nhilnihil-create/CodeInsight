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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans=0;
    if(a>b){
        ans+=b;
    }
    else{
        ans+=a;
    }
    if(c>d) ans+=d;
    else ans+=c;

    cout << ans;

    return 0;
}