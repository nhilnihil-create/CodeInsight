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
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    vector<int> a(100001);
    vector<int> b(100001);
    rep(i,100001){
        a[i] = 0;
        b[i] = 0;
    }
    for(int i=0;i<n-1;i+=2){
        a[v[i]] += 1;
        b[v[i+1]] += 1;
    }
    pair<int,int> a1,a2,b1,b2;
    a1 = make_pair(0,0);
    a2 = make_pair(0,0);
    b1 = make_pair(0,0);
    b2 = make_pair(0,0);
    rep(i,100001){
        // if(a[i]!=0){
        //     cout << "a "  << i << " "<<  a[i] << endl;
        // }
        // if(b[i]!=0){
        //     cout << "b " << i << " " <<  b[i] << endl;
        // }
            
        if(a1.first<a[i]){
            a2.first = a1.first;
            a2.second = a1.second;
            a1.first = a[i];
            a1.second = i;
        }else if(a2.first<a[i]){
            a2.first = a[i];
            a2.second = i;
        }
        if(b1.first<b[i]){
            b2.first = b1.first;
            b2.second = b1.second;
            b1.first = b[i];
            b1.second = i;
        }else if(b2.first<b[i]){
            b2.first = b[i];
            b2.second = i;
        }
    }
    // cout << a1.first << " " << a1.second << endl;
    // cout << b1.first << " " << b1.second << endl;
    if(a1.second!=b1.second){
        cout << n - a1.first - b1.first << endl;
    }else{
        int ans = max ( a1.first+b2.first,a2.first+b1.first);
        cout << n - ans << endl;
    }
 
    return 0;
}