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
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<int> a(n);
    vector<int> b(m);
    int ma=-101,mi=101;
    rep(i,n) {
        cin >> a[i];
        ma = max(ma,a[i]);
    }
    rep(i,m) {
        cin >> b[i];
        mi = min(mi,b[i]);
    }

    // cout << ma << " " << mi << endl;
    for(int i = ma+1;i <= mi;i++){
        if((i>x)&&(i<=y)){
            cout << "No War" << endl;
            return 0; 
        }
    }
    cout << "War" << endl;
    
    return 0;
}