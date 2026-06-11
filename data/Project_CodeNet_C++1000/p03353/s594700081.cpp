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
    string s1;
    cin >> s1;
    int k;
    cin >> k;
    int n = s1.size();
    vector<string> a(0);
    
    for(int i=1;i<min(6,n+1);i++){
        for(int j=0;j<n-i+1;j++){
            string tmp = s1.substr(j,i);
            a.push_back(tmp);
        }
    }
    // rep(i,a.size()){
    //     if(a[i]=="\n"){
    //         a[i] == "zzzzz";
    //     }
    // }
    sort(a.begin(),a.end());
    // rep(i,500){
    //     cout << a[i] << endl;
    // }
    if(n==1){
        cout << s1 << endl;
        return 0;
    }
    if(k==1){
        cout << a[0] << endl;
        return 0;
    }
    int cnt = 0;
    for(int i=1;i<a.size();i++){
        if(a[i]==a[i-1]){
            k++;
        }
        if(k==i+1){
            // cout << k-1 << endl;
            cout << a[k-1] << endl;
            return 0;
        }

    }

    return 0;
}