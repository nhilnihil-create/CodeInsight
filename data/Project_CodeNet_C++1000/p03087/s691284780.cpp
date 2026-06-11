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
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n+1,0);
    rep(i,n){
        if(s[i] =='A' && s[i+1] == 'C'){
            a[i+1]+=1;
        }
    }
    rep(i,n){
        a[i+1] = a[i] + a[i+1];
    }
    // rep(i,n){
    //     cout << a[i] << endl;
    // }
    rep(i,q){
        int x,y;
        cin >> x >> y;
        if(x==1){
            cout << a[y-1] << endl;
        }else{
            cout << a[y-1] - a[x-1] << endl; 
        }
    }


    return 0;
}