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
    vector<string> a(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n-1){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                cout << "No";
                return 0;
            }
        }
    }
    rep(i,n-1){
        if(a[i][a[i].size()-1]==a[i+1][0]){
            continue;
        }
        else{
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";


    return 0;
}