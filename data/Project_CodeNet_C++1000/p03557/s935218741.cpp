#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
int main () {
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)cin>>c[i];
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    long long x=0;
    for(int i=0;i<n;i++){
        x+=(lower_bound(a,a+n,b[i])-a)*(n-(upper_bound(c,c+n,b[i])-c));
    }
    cout<<x<<endl;
    return 0 ;
}

 
