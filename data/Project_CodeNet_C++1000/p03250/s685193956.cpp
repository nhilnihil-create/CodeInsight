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
    vector<int> a(3);
    rep(i,3) cin >> a[i];
    sort(a.begin(),a.end());

    cout << a[2] *10 + a[1] + a[0] ;

    return 0;
}