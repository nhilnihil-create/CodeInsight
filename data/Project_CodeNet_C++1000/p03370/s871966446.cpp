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

    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    int m=1000;
    int tank=0;
    rep(i,n){
        cin >> a[i];
        tank += a[i];
        m = min(m,a[i]);
    }
    int cnt=n;
    cnt+= (x-tank)/m;
    cout << cnt;
    

    return 0;
}