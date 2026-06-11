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

    // cout << n << endl;
    
    double cent;
    cent = (double) (n+1)/2;

    // cout << cent <<endl;

    // 0 count |index-center|
    rep(i,n){
        if(s[i]=='0'){
            if(i==n-1){
                cout << n << endl;
                return 0;
            }
            continue;
        }
        else{
            break;
        }
    }
    rep(i,n){
        if(s[i]=='1'){
            if(i==n-1){
                cout << n << endl;
                return 0;
            }
            
            continue;
        }
        else{
            break;
        }
    }

    double res1=n,res2=n;
    rep(i,n){
        if(s[i]=='0'){
            double m = abs(i+1-cent);
            res1 = min (res1,m);
            // cout << m << endl;
        }
        else{
            double m = abs(i+1-cent);
            res2 = min (res2,m);
            // cout << m << endl;
        }
    }

    // cout << cent <<endl;

    // cout << res1 << endl;
    // cout << res2 << endl;

    double ans = max(res1,res2);

    // cout << ans << endl;

    int a = ans + cent;

    // if(n%2==0){
    //     cout << a <<endl;
    // }
    // else{
    //     cout << a-1 <<endl;
    // }
    cout << a-1 << endl;

    return 0;
}