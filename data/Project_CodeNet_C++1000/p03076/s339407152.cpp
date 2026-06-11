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
    vector<int> a(5);
    int m=0;
    int ans=0;
    rep(i,5){
        cin >> a[i];
    }
    rep(i,5){
        if(a[i]%10==0){
            ans+=a[i];
        }
        else{
            int l = 10-a[i]%10;
            ans+=a[i]+l;
            m = max(m,l);
        }
    }
    cout << ans-m;
    



    return 0;
}