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
    int n,m;
    cin >> n >> m;
    vector<int> a(m+1);
    rep(i,n){
        int k;
        cin >> k;
        rep(i,k){
            int j;
            cin >> j;
            a[j]+=1;
        }
    }
    int cnt=0;
    rep(i,m+1){
        if(a[i]==n){
            cnt+=1;
        }
    }
    cout << cnt;


    return 0;
}