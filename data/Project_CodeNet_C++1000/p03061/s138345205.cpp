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

int gcd(int a, int b){
    return( a ? gcd(b%a,a):b);
}

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> left(n);
    vector<int> right(n);
    rep(i,n){
        cin >> a[i];
    }
    left[0]=a[0];
    right[n-1]=a[n-1];
    for(int i=1;i<n;i++){
        left[i] = gcd(left[i-1],a[i]);
        right[n-1-i] = gcd(right[n-i],a[n-1-i]);
    }
    int ans = max(right[1],left[n-2]);
    for(int i=1;i<n-1;i++){
        ans = max(ans,gcd(left[i-1],right[i+1]));
    }
    cout << ans << endl;
    return 0;
}