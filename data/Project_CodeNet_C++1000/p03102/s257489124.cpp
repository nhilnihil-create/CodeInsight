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
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i,m){
        cin >> b[i];
    }
    int cnt=0;
    rep(i,n){
        int sum=c;
        rep(i,m){
            int m;
            cin >> m;
            sum+=m*b[i];
        }
        if(sum>0){
            cnt+=1;
        }
    }
    cout << cnt;

    return 0;
}