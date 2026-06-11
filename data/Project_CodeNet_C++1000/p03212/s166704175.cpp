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

int ans = 0;
int n;

int dfs(int a){
    if(a<=n){
        bool a3=false,a5=false,a7=false;
        int m = a;
        while(m>0){
            if(m%10 == 3) a3 = true;
            if(m%10 == 5) a5 = true;
            if(m%10 == 7) a7 = true;
            m/=10;
        }
        if(a3&&a5&&a7) ans = ans + 1;
    }

    
    if(a<=100000000&&a<=n){
        dfs(10*a+3);
        dfs(10*a+5);
        dfs(10*a+7);
    }
    return 0;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    dfs(3);
    dfs(5);
    dfs(7);
    cout << ans << endl;

    return 0;
}