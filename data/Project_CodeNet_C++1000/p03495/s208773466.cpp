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
    vector<int> a(n);
    rep(i,n){
        a[i]=0;
    }
    rep(i,n){
        int m;
        cin >> m;
        a[m-1]+=1;
    }
    sort(a.begin(),a.end(),greater<int>());

    int cnt=0;
    rep(i,k){
        cnt+=a[i];
    }
    cout << n-cnt << endl;

    return 0;
}