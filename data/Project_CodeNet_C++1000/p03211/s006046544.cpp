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
    string s;
    cin >> s;
    int n = s.size();
    int ans=753;
    rep(i,n-2){
        string m;
        m = s.substr(i,3);
        ans = min(ans,abs(753-stoi(m)));
    }
    cout << ans;

    return 0;
}