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
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;

    rep(i,a){
        if(s[i]=='-'){
            cout << "No";
            return 0;
        }
    }
    if(s[a]!='-'){
        cout << "No";
        return 0;
    }
    // cout << "Hello";
    for(int j=a+1;j<a+b+1;j++){
        if(s[j]=='-'){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}